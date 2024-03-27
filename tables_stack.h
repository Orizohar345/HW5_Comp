#ifndef TABLES_STACK_H
#define TABLES_STACK_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include "hw3_output.hpp"

class Entry {
public:
    std::string name;
    std::string type;
    std::string var;
    int val;
    int offset;

    Entry(const std::string& name, const std::string& type, std::string& var, int val = 0, int offset = 0)
        : name(name), type(type), var(var), val(val), offset(offset) {}
    ~Entry() = default;
    Entry(const Entry& other) : name(other.name), type(other.type), val(other.val), offset(other.offset) {}
};

class TablesStack {
private:
    std::vector<std::vector<Entry> > symbol_table;
    std::vector<int> offsets_stack;
    std::vector<std::vector<Entry> > func_table;

public:
    // Constructor that creates an empty symbol table with one empty table
    TablesStack();

    ~TablesStack() = default;

    // Push a new empty table onto the stack
    void addNewTable();


    void removeTopTable();

    // Check if the stack is empty
    bool empty() const;

    // Get the size of the stack (number of tables stored)
    size_t size() const;

    // Access the top table (without modifying the stack)
    std::vector<Entry>& getTopTable();

    // Add Entry to the table in the top of the stack.
    void addToTopTable(Entry&& entry, bool is_func = false);

    bool entryExists(const std::string& name, bool is_func = false) const;

    Entry getEntry(const std::string& name) const;

    void entryChangeVal(const std::string& name, int val, std::string var);
};

#endif
