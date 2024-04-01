#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <string>
#include "hw3_output.hpp"
#include "bp.hpp"
#include "tables_stack.h"

class Node {
public:
    std::string text;

    // Constructor
    Node() = default;

    Node(const std::string& text) : text(text) {}

    // Virtual destructor to ensure proper cleanup of derived types
    virtual ~Node() {}

    // Copy constructor
    Node(const Node& other) : text(other.text) {}

    // Copy assignment operator
    Node& operator=(const Node& other) {
        if (this != &other) {
            text = other.text;
        }
        return *this;
    }

    // Move constructor
    Node(Node&& other) noexcept : text(std::move(other.text)) {}

    // Move assignment operator
    Node& operator=(Node&& other) noexcept {
        if (this != &other) {
            text = std::move(other.text);
        }
        return *this;
    }
};

#define YYSTYPE Node*

// Class for types, same as Node
class Type : public Node {
public:
    using Node::Node; // Inherit constructors
};

class Exp : public Node {
public:
    std::string type;
    std::string reg;
    int val;
    bool is_const;

    // Constructor
    Exp() = default;

    Exp(const std::string& text, const std::string& type, std::string reg, int val, bool is_const)
        : Node(text), type(type), reg(reg), val(val), is_const(is_const) {}

    // Copy constructor
    Exp(const Exp& other)
        : Node(other), type(other.type), reg(other.reg), val(other.val), is_const(other.is_const) {}

    // Copy assignment operator
    Exp& operator=(const Exp& other) {
        if (this != &other) {
            Node::operator=(other); // Call base class assignment operator
            type = other.type;
            val = other.val;
            is_const = other.is_const;
        }
        return *this;
    }
};

class Call : public Exp {
public:
    using Exp::Exp;
};

class BoolOp : public Exp {
public:
    std::string trueLabel, falseLabel, endLabel, nextLabel;

    BoolOp(Exp op1);
    virtual void emitInitialPart() = 0;
    virtual std::string finalizeOperation(Exp* operand2) = 0;
};

class BoolAndOperation : public BoolOp {
public:
    BoolAndOperation(Exp op1);
    void emitInitialPart() override;
    std::string finalizeOperation(Exp* operand2) override;
};

class BoolOrOperation : public BoolOp {
public:
    BoolOrOperation(Exp op1);
    void emitInitialPart() override;
    std::string finalizeOperation(Exp* operand2) override;
};

class IfOp : public Exp {
public:
    std::string endLabel, nextLabel, exitLabel;
    bool is_else;
    IfOp(Exp op1);
    void emitInitialPart();
    void finalizeOperation();
    void exitOperation();
    void emitMiddle();

};

class IfElseOp : public Exp {
public:
    std::string trueLabel, falseLabel, endLabel;

    IfElseOp(Exp op1);
    void emitInitialPart();
    void emitMiddle();
    void finalizeOperation();
};


class BoolIfOperation : public BoolOp {
public:
    BoolIfOperation(Exp op1);
    void emitInitialPart() override;
    std::string finalizeOperation(Exp* operand2) override;
};


void verifyNumeric(std::string type1, std::string type2, int lineno);
std::string verifyBinop(std::string type1, std::string type2, int lineno);
int calcBinop(std::string type1, std::string type2, int val1, int val2, std::string operation, int lineno);
std::string verifyFunc(std::string func_id, std::string arg_type, int lineno);
void finalizeResult(Exp* res, const std::string& result, const std::string& op);
std::string determineOperationCode(const std::string& op);

void generateDeclarationCode();
void generateBinopCode(Exp *res, std::string operand1, std::string operand2, const std::string& op);
void generateNumCode(Exp* num);
void generateNumByteCode(Exp* num);
std::string generateIdCode(std::string val = "0");
std::string handleExp(Exp* exp, std::string boolCompare = "Assign");
std::string generateLoad(std::string name);
void generateStore(std::string src, std::string target);
std::string generateGlobalString(std::string str);
void generatePrintCode(std::string str, std::string arg);
void generatePrintiCode(std::string arg);
std::string generateReadiCode(std::string arg);
void generateTrueCode(Exp* b);
void generateFalseCode(Exp* b);
void generateNotCode(Exp* res, std::string operand);
void generateRelopEqCode(Exp *res, std::string operand1, std::string operand2, const std::string& op);
void generateRelopRelCode(Exp *res, std::string operand1, std::string operand2, const std::string& op);

#endif
