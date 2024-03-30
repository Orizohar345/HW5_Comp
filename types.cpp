
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


void generateBinopCode(Exp *res, std::string operand1, std::string operand2, const std::string& op) {
    if (op == "/") {
        // Division operation with zero-check
        std::string labelNoDivZero = buffer.freshLabel();
        std::string labelDivZero = buffer.freshLabel();
        std::string endLabel = buffer.freshLabel();
        std::string checkZero = buffer.freshReg();
        std::string divResult = buffer.freshReg();  // Prepare variable for division result

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
        buffer.emit(divResult + " = sdiv i32 " + operand1 + ", " + operand2);
        buffer.emit("br label %" + endLabel);

        // Converge back with a phi node
        buffer.emit(endLabel + ":");
        std::string result = buffer.freshReg();
        buffer.emit(result + " = phi i32 [ -1, %" + labelDivZero + "], [" + divResult + ", %" + labelNoDivZero + "]");

        // Proceed with result handling
        finalizeResult(res, result, op);
    } else {
        // Handle other binary operations without division by zero check
        std::string operationCode = determineOperationCode(op);
        std::string result = buffer.freshReg();
        buffer.emit(result + " = " + operationCode + " i32 " + operand1 + ", " + operand2);

        // Proceed with result handling
        finalizeResult(res, result, op);
    }
}

void finalizeResult(Exp* res, const std::string& result, const std::string& op) {
    if (res->type == "BYTE" && op != "/") { // Division already handled in phi
        std::string byteResult = buffer.freshReg();
        buffer.emit(byteResult + " = and i32 " + result + ", 255");
        res->reg = byteResult;
    } else {
        res->reg = result;
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
        num->reg = buffer.freshReg();
        buffer.emit(num->reg + " = add i32 " + to_string(num->val) + ", 0");
}

void generateNumByteCode(Exp* num) {
    // First, generate a fresh variable for the initial number
    num->reg = buffer.freshReg();
    // Emit the LLVM IR code to assign the initial value to the variable
    buffer.emit(num->reg + " = add i32 0, " + to_string(num->val));

    // Now, create a new variable for the result after ensuring it's within the byte range
    std::string byteResult = buffer.freshReg();
    // Apply bitwise AND with 255 to constrain the value within the byte range
    buffer.emit(byteResult + " = and i32 " + num->reg + ", 255");

    // Update num->var to the new variable holding the constrained value
    num->reg = byteResult;
}


std::string generateIdCode(std::string val) {
        std::string ret_val = buffer.freshReg();
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

std::string handleExp(Exp* exp) {
    if (exp->is_const) {
        // If the expression is a constant, just return its associated variable name
        return exp->reg;
    } else {
        std::string var = generateLoad(exp->text);
        std::string reg = buffer.freshReg();
        buffer.emit(reg + " = load i32, i32* " + var);
        return reg;
    }
}

std::string generateLoad(std::string name) {
        Entry entry = table_stack.getEntry(name);
        std::string var = buffer.freshVar();
        buffer.emit(var + " = getelementptr [50 x i32], [50 x i32]* " + buffer.stackPtr + ", i32 0, i32 " + to_string(entry.offset));
        return var;
}

void generateStore(std::string src, std::string target) {
        buffer.emit("store i32 " + src + ", i32* " + target);
}

std::string generateGlobalString(std::string str) {
        static int string_counter = 0;
        std::string global_string;

        string_counter++;
        global_string = "@.global_string" + to_string(string_counter);
        buffer.emitGlobal(global_string + " = constant [" + to_string(str.size() + 1) + " x i8] c\"" + str + "\\00\"");

        return global_string;
}

void generatePrintCode(std::string str, std::string arg) {
        std::string str_len = to_string(str.size() + 1);
        buffer.emit("call void @print(i8* getelementptr ([" + str_len + " x i8], [" +str_len + " x i8]* " + arg +", i32 0, i32 0))");
}

void generatePrintiCode(std::string arg) {
        buffer.emit("call void @printi(i32 " + arg + ")");
}

std::string generateReadiCode(std::string arg) {
        std::string reg = buffer.freshReg();
        buffer.emit(reg + " = call i32 @readi(i32 " + arg + ")");
        return reg;
}

void generateAndCode(Exp* res, std::string operand1, std::string operand2){
    std::string trueLabel = buffer.freshLabel();
    std::string falseLabel = buffer.freshLabel();
    std::string endLabel = buffer.freshLabel();
    std::string label0 = buffer.freshLabel();

    std::string op1 = buffer.freshVar();
    buffer.emit(op1 + " = icmp eq i32 " + operand1 + ", 0");
    buffer.emit("br i1 " + op1 + ", label %" + falseLabel + ", label %" + label0);

    buffer.emit(label0 + ":");
    std::string op2 = buffer.freshVar();
    buffer.emit(op2 + " = icmp eq i32 " + operand2 + ", 0");
    buffer.emit("br i1 " + op2 + ", label %" + falseLabel + ", label %" + trueLabel);

    buffer.emit(falseLabel + ":");
    buffer.emit("br i1 label %" + endLabel);

    buffer.emit(trueLabel + ":");
    buffer.emit("br i1 label %" + endLabel);

    buffer.emit(endLabel + ":");
    std::string resultVar = buffer.freshVar();
    buffer.emit(resultVar + " = phi i32 [ 1, %" + trueLabel + "], [ 0, %" + falseLabel + "]");
    res->reg = resultVar;
}

void generateOrCode(Exp* res, std::string operand1, std::string operand2){
    std::string trueLabel = buffer.freshLabel();
    std::string falseLabel = buffer.freshLabel();
    std::string endLabel = buffer.freshLabel();
    std::string label0 = buffer.freshLabel();

    std::string op1 = buffer.freshVar();
    buffer.emit(op1 + " = icmp eq i32 " + operand1 + ", 0");
    buffer.emit("br i1 " + op1 + ", label %" + label0 + ", label %" + trueLabel);

    buffer.emit(label0 + ":");
    std::string op2 = buffer.freshVar();
    buffer.emit(op2 + " = icmp eq i32 " + operand2 + ", 0");
    buffer.emit("br i1 " + op2 + ", label %" + falseLabel + ", label %" + trueLabel);

    buffer.emit(falseLabel + ":");
    buffer.emit("br i1 label %" + endLabel);

    buffer.emit(trueLabel + ":");
    buffer.emit("br i1 label %" + endLabel);

    buffer.emit(endLabel + ":");
    std::string resultVar = buffer.freshVar();
    buffer.emit(resultVar + " = phi i32 [ 1, %" + trueLabel + "], [ 0, %" + falseLabel + "]");
    res->reg = resultVar;
}

void generateTrueCode(Exp* b) {
        b->reg = buffer.freshReg();
        buffer.emit(b->reg + " = add i32 " + to_string(b->val) + ", 0");
}

void generateFalseCode(Exp* b) {
        b->reg = buffer.freshVar();
        buffer.emit(b->reg + " = add i32 " + to_string(b->val) + ", 0");
}

void generateNotCode(Exp* res, const std::string b){
        res->reg = buffer.freshVar();
        buffer.emit(res->reg + " = icmp eq i32 " + b + ", 0" );
}
