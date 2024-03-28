
#include "types.h"

extern CodeBuffer buffer;
extern TablesStack table_stack;


void verifyNumeric(std::string type1, std::string type2, int lineno)
{
        if ((type1 != "INT" and type1 != "BYTE") or (type2 != "INT" and type2 != "BYTE")) {
                output::errorMismatch(lineno);
                exit(1);
        }
}

std::string verifyBinop(std::string type1, std::string type2, int lineno)
{
        verifyNumeric(type1, type2, lineno);
        if ((type1 != "INT" and type1 != "BYTE") or (type2 != "INT" and type2 != "BYTE")) {
                output::errorMismatch(lineno);
                exit(1);
        }

        if (type1 == "BYTE" and type2 == "BYTE")
                return "BYTE";

        return "INT";
}

std::string verifyFunc(std::string func_id, std::string arg_type, int lineno) {
        if (func_id == "print") {
                if (arg_type != "STRING") {
                        output::errorPrototypeMismatch(lineno, func_id, "STRING");
                        exit(1);
                }

                return "VOID";
        } else if (func_id == "printi") {
                if (arg_type != "INT" and arg_type != "BYTE" ) {
                        output::errorPrototypeMismatch(lineno, func_id,  "INT");
                        exit(1);
                }

                return "VOID";
        } else if (func_id == "readi") {
                if (arg_type != "INT" and arg_type != "BYTE" ) {
                        output::errorPrototypeMismatch(lineno, func_id, "INT");
                        exit(1);
                }

                return "INT";
        }


        output::errorUndefFunc(lineno, func_id);
        exit(1);
}

int calcBinop(std::string type1, std::string type2, int val1, int val2, std::string operation, int lineno) {
        int res;

        if (operation == "*")
                res = val1 * val2;
        else if (operation == "+")
                res = val1 + val2;
        else if (operation == "-")
                res = val1 - val2;
        else if (operation == "/")
                res = val1 / val2;

        if (type1 == "BYTE" && type2 == "BYTE") {
                if (res > 255) {
                        res = res & 255;
                }
        }

        return res;
}


void generateBinopCode(Exp* res, std::string operand1, std::string operand2, const std::string& op) {
    if (op == "/") {
        // Division operation with zero-check
        std::string labelNoDivZero = buffer.freshLabel();
        std::string labelDivZero = buffer.freshLabel();
        std::string endLabel = buffer.freshLabel();
        std::string checkZero = buffer.freshVar();
        std::string divResultVar = buffer.freshVar();  // Prepare variable for division result

        // Emit check for divisor being zero
        buffer.emit(checkZero + " = icmp eq i32 " + operand2 + ", 0");
        buffer.emit("br i1 " + checkZero + ", label %" + labelDivZero + ", label %" + labelNoDivZero);

        // Division by zero handling
        buffer.emit(labelDivZero + ":");
        buffer.emit("call void @print(i8* getelementptr ([24 x i8], [24 x i8]* @.div_zero_error_msg, i32 0, i32 0))");
        // Exit with status code 1
        buffer.emit("call void @exit(i32 1)");
        buffer.emit("br label %" + endLabel);

        // Valid division
        buffer.emit(labelNoDivZero + ":");
        buffer.emit(divResultVar + " = sdiv i32 " + operand1 + ", " + operand2);
        buffer.emit("br label %" + endLabel);

        // Converge back with a phi node
        buffer.emit(endLabel + ":");
        std::string resultVar = buffer.freshVar();
        buffer.emit(resultVar + " = phi i32 [ -1, %" + labelDivZero + "], [" + divResultVar + ", %" + labelNoDivZero + "]");

        // Proceed with result handling
        finalizeResult(res, resultVar, op);
    } else {
        // Handle other binary operations without division by zero check
        std::string operationCode = determineOperationCode(op);
        std::string resultVar = buffer.freshVar();
        buffer.emit(resultVar + " = " + operationCode + " i32 " + operand1 + ", " + operand2);

        // Proceed with result handling
        finalizeResult(res, resultVar, op);
    }
}

void finalizeResult(Exp* res, const std::string& resultVar, const std::string& op) {
    if (res->type == "BYTE" && op != "/") { // Division already handled in phi
        std::string byteResultVar = buffer.freshVar();
        buffer.emit(byteResultVar + " = and i32 " + resultVar + ", 255");
        res->var = byteResultVar;
    } else {
        res->var = resultVar;
    }
}

std::string determineOperationCode(const std::string& op) {
    if (op == "+") return "add";
    else if (op == "-") return "sub";
    else if (op == "*") return "mul";
    // Division is handled separately
    return "";
}




void generateNumCode(Exp* num) {
        num->var = buffer.freshVar();
        buffer.emit(num->var + " = add i32 " + to_string(num->val) + ", 0");
}

void generateNumByteCode(Exp* num) {
    // First, generate a fresh variable for the initial number
    num->var = buffer.freshVar();
    // Emit the LLVM IR code to assign the initial value to the variable
    buffer.emit(num->var + " = add i32 0, " + to_string(num->val));

    // Now, create a new variable for the result after ensuring it's within the byte range
    std::string byteResultVar = buffer.freshVar();
    // Apply bitwise AND with 255 to constrain the value within the byte range
    buffer.emit(byteResultVar + " = and i32 " + num->var + ", 255");

    // Update num->var to the new variable holding the constrained value
    num->var = byteResultVar;
}


std::string generateIdCode(std::string val) {
        std::string ret_val = buffer.freshVar();
        buffer.emit(ret_val + " = add i32 " + val + ", 0");
        return ret_val;
}

void generateFuncUsageCode(const std::string& func_name, const std::string& arg) {
    // Compare function name to determine which function to call
    if (func_name == "readi") {
        // Call readi function with the provided argument
        buffer.emit("%result = call i32 @readi(i32 " + arg + ")");
    } else if (func_name == "printi") {
        // Call printi function with the provided argument
        buffer.emit("call void @printi(i32 " + arg + ")");
    } else if (func_name == "print") {
        // Call print function with the provided argument
        buffer.emit("call void @print(i8* " + arg + ")");
    } else {
        std::cout << func_name << arg << std::endl;
        // Handle invalid function name
        return;
    }
}

std::string handleExpVar(Exp* exp) {
    if (exp->is_const) {
        // If the expression is a constant, just return its associated variable name
        return exp->var;
    } else {
        // If the expression is not a constant, get the entry from the symbol table
        Entry entry = table_stack.getEntry(exp->text);

        // Create a fresh variable to hold the loaded value
        std::string freshVar = buffer.freshVar();

        // Generate the LLVM IR code to load the variable's value from its memory address
        buffer.emit(freshVar + " = load " + "i32" + ", " + "i32" + "* " + entry.var);

        // Return the name of the fresh variable holding the loaded value
        return freshVar;
    }
}

std::string generateDeclareVar(const std::string& initialValue) {
    // Generate a fresh variable name for LLVM IR (address of the variable)
    std::string varAddr = buffer.freshVar();

    // Emit LLVM IR code to allocate space for the variable
    buffer.emit(varAddr + " = alloca i32");

    // Emit LLVM IR code to store the initial value into this variable
    buffer.emit("store i32 " + initialValue + ", i32* " + varAddr);

    // Return the address (name) of the variable for further use
    return varAddr;
}
