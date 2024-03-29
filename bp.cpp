#include "bp.hpp"
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

bool replace(string& str, const string& from, const string& to, const BranchLabelIndex index);

CodeBuffer::CodeBuffer() : buffer(), globalDefs() {}

CodeBuffer &CodeBuffer::instance() {
	static CodeBuffer inst;//only instance
	return inst;
}

void CodeBuffer::initDeclerations() {
    // Emit declarations for external functions
    emit("declare i32 @scanf(i8*, ...)");
    emit("declare i32 @printf(i8*, ...)");
    emit("declare void @exit(i32)");

    // Emit global constants for format specifiers
    emit("@.int_specifier_scan = constant [3 x i8] c\"%d\\00\"");
    emit("@.int_specifier = constant [4 x i8] c\"%d\\0A\\00\"");
    emit("@.str_specifier = constant [4 x i8] c\"%s\\0A\\00\"");
    emit("@.div_zero_error_msg = constant [24 x i8] c\"Error division by zero\\0A\\00\"");

    // Define the readi function
    emit("define i32 @readi(i32) {");
    emit("  %ret_val = alloca i32");
    emit("  %spec_ptr = getelementptr [3 x i8], [3 x i8]* @.int_specifier_scan, i32 0, i32 0");
    emit("  call i32 (i8*, ...) @scanf(i8* %spec_ptr, i32* %ret_val)");
    emit("  %val = load i32, i32* %ret_val");
    emit("  ret i32 %val");
    emit("}");

    // Define the printi function
    emit("define void @printi(i32) {");
    emit("  %spec_ptr = getelementptr [4 x i8], [4 x i8]* @.int_specifier, i32 0, i32 0");
    emit("  call i32 (i8*, ...) @printf(i8* %spec_ptr, i32 %0)");
    emit("  ret void");
    emit("}");

    // Define the print function
    emit("define void @print(i8*) {");
    emit("  %spec_ptr = getelementptr [4 x i8], [4 x i8]* @.str_specifier, i32 0, i32 0");
    emit("  call i32 (i8*, ...) @printf(i8* %spec_ptr, i8* %0)");
    emit("  ret void");
    emit("}");
}

void  CodeBuffer::initMain() {
    emit("define i32 @main() {");
    stackPtr = "%vars_buffer";
    emit(stackPtr + " = alloca [50 x i32]");
}

void  CodeBuffer::finishMain() {
    emit("ret i32 0");
    emit("}");
}

string CodeBuffer::genLabel() {
    std::string label = freshLabel();
    emit(label + ":");
    return label;
}

string CodeBuffer::freshLabel(){
	std::stringstream label;
	label << "label_" << labels_num++;
	return label.str();
}

string CodeBuffer::freshVar(){
	std::stringstream var;
	var << "%var_" << vars_num++;
	return var.str();
}

string CodeBuffer::freshReg(){
	std::stringstream reg;
	reg << "%reg_" << vars_num++;
	return reg.str();
}

int CodeBuffer::emit(const string &s){
    buffer.push_back(s);
	return buffer.size() - 1;
}

void CodeBuffer::bpatch(const vector<pair<int,BranchLabelIndex>>& address_list, const std::string &label){
    for(vector<pair<int,BranchLabelIndex>>::const_iterator i = address_list.begin(); i != address_list.end(); i++){
    	int address = (*i).first;
    	BranchLabelIndex labelIndex = (*i).second;
		replace(buffer[address], "@", "%" + label, labelIndex);
    }
}

void CodeBuffer::printCodeBuffer(){
	for (std::vector<string>::const_iterator it = buffer.begin(); it != buffer.end(); ++it)
	{
		cout << *it << endl;
    }
}

vector<pair<int,BranchLabelIndex>> CodeBuffer::makelist(pair<int,BranchLabelIndex> item)
{
	vector<pair<int,BranchLabelIndex>> newList;
	newList.push_back(item);
	return newList;
}

vector<pair<int,BranchLabelIndex>> CodeBuffer::merge(const vector<pair<int,BranchLabelIndex>> &l1,const vector<pair<int,BranchLabelIndex>> &l2)
{
	vector<pair<int,BranchLabelIndex>> newList(l1.begin(),l1.end());
	newList.insert(newList.end(),l2.begin(),l2.end());
	return newList;
}

// ******** Methods to handle the global section ********** //
void CodeBuffer::emitGlobal(const std::string& dataLine)
{
	globalDefs.push_back(dataLine);
}

void CodeBuffer::printGlobalBuffer()
{
	for (vector<string>::const_iterator it = globalDefs.begin(); it != globalDefs.end(); ++it)
	{
		cout << *it << endl;
	}
}

// ******** Helper Methods ********** //
bool replace(string& str, const string& from, const string& to, const BranchLabelIndex index) {
	size_t pos;
	if (index == SECOND) {
		pos = str.find_last_of(from);
	}
	else { //FIRST
		pos = str.find_first_of(from);
	}
    if (pos == string::npos)
        return false;
    str.replace(pos, from.length(), to);
    return true;
}
