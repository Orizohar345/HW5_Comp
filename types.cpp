
#include "types.h"

extern CodeBuffer buffer;


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

int verifyByte(std::string type1, std::string type2, int val1, int val2, std::string operation, int lineno) {
        int res;

        if (operation == "MULT")
                res = val1 * val2;
        else if (operation == "ADD")
                res = val1 + val2;

        if (type1 == "BYTE" && type2 == "BYTE") {
                if (res > 255) {
                        output::errorByteTooLarge(lineno, std::to_string(res));
                        exit(1);
                }
        }

        return res;
}


void generateBinopCode(Exp *res, const Exp &operand1, const Exp &operand2, const string &op) {
    res->var = buffer.freshVar();
    std::string code = res->var + " = ";
    if (op == "+") {
        code += "add";
    } else if (op == "-") {
        code += "sub";
    } else if (op == "*") {
        code += "mul";
    } else {
        if (res->type == "INT") {
            code += "sdiv";
        } else {
            code += "udiv";
        }
    }
    if (op == "/") {
        buffer.emit("call void @check_division(i32 " + operand2.var + ")");
        buffer.emit(code + " i32 " + operand1.var + ", " + operand2.var);
    } else {
        buffer.emit(code + " i32 " + operand1.var + ", " + operand2.var);
        if (res->type == "BYTE") {
            string old_var = res->var;
            res->reg = buffer.freshVar();
            buffer.emit(res->val + " = and i32 255, " + old_val);
        }
    }
}

void generateNumCode(Exp* num) {
        num->var = buffer.freshVar();
        buffer.emit(num->var + " = add i32 " + to_string(num->val) + ", 0");
}

std::string generateIdCodeDefault() {
        ret_val = buffer.freshVar();
        buffer.emit(ret_val + " = add i32 " + "0" + ", 0");
        return ret_val;
}
