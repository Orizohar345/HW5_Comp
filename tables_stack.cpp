#include "tables_stack.h"

TablesStack::TablesStack() {
    symbol_table.push_back(std::vector<Entry>());
    offsets_stack.push_back(0);
    TablesStack::addToTopTable(Entry("print", output::makeFunctionType("STRING", "VOID"), "T0"), true);
    TablesStack::addToTopTable(Entry("printi", output::makeFunctionType("INT", "VOID"), "T0"), true);
    TablesStack::addToTopTable(Entry("readi", output::makeFunctionType("INT", "INT"), "T0"), true);
}

void TablesStack::addNewTable() {
    // Push an empty table onto the stack
    symbol_table.push_back(std::vector<Entry>());
}


bool TablesStack::empty() const {
    return symbol_table.empty();
}

size_t TablesStack::size() const {
    return symbol_table.size();
}

std::vector<Entry>& TablesStack::getTopTable() {
    if (TablesStack::empty()) {
        throw std::runtime_error("Stack is empty");
    }
    return symbol_table.back();
}
void TablesStack::removeTopTable() {
    if (empty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    std::vector<Entry>& topTable = TablesStack::getTopTable();
    if (!topTable.empty())
        for (const auto& entry : topTable) {
            if (entry.type == "WHILE")
                continue;
            if (!offsets_stack.empty())
                offsets_stack.pop_back();
        }
    symbol_table.pop_back();
}

void TablesStack::addToTopTable(Entry entry, bool is_func) {

    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    if (!is_func) {
        entry.offset = offsets_stack.back();
        offsets_stack.push_back(offsets_stack.back()+1);
    }
    TablesStack::getTopTable().push_back(entry); // Add entry to the back of the top table
}



bool TablesStack::entryExists(const std::string& name, bool is_func) const {
    // Iterate through tables from top to bottom
        for (const auto& table : symbol_table) {
            auto it = std::find_if(table.begin(), table.end(), [&name](const Entry& entry) { return entry.name == name; });
            if (it != table.end()) {
                return true; // Return true if the entry is found
            }
        }
    return false;

}

Entry TablesStack::getEntry(const std::string& name) const {
    // Iterate through tables from top to bottom
    for (const auto& table : symbol_table) {
        auto it = std::find_if(table.begin(), table.end(), [&name](const Entry& entry) { return entry.name == name && entry.type != "WHILE"; });
        if (it != table.end()) {
            return (*it); // Return the found Entry
        }
    }
    throw std::runtime_error("Entry not found in the stack");
}

void TablesStack::entryChangeVal(const std::string& name, int val) {
    // Iterate through tables from top to bottom
    for (auto& table : symbol_table) {
        auto it = std::find_if(table.begin(), table.end(), [&name](const Entry& entry) { return entry.name == name; });
        if (it != table.end()) {
            it->val = val; // Return the found Entry
        }
    }
}
