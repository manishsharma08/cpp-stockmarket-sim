#include "../include/transaction.h"
#include <iostream>

Transaction::Transaction(std::string symbol , double value , int quantity , TransactionType type)
    : symbol(symbol),value(value),quantity(quantity),type(type) // what is this? -> extracting the private members and assigning them to params
{
}; // initializing constructor


// creating getters (WHY? -> BECAUSE WITHOUT THEM WE WOULD NOT BE ABLE TO READ THE PRIVATE DATA OF CLASS TRANSACTION)
std::string Transaction::getSymbol() const{
    return symbol;
}

double Transaction::getValue() const{
    return value;
}

int Transaction::getQuantity() const{
    return quantity;
}

TransactionType Transaction::getType() const{
    return type;
}// without all of this the data would be garbage