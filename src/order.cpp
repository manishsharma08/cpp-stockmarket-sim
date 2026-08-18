#include "../include/order.h"

Order::Order(std::string symbol , int quantity , OrderType type)
    : symbol(symbol) , quantity(quantity) , type(type)
{    
};

std::string Order::getSymbol() const{
    return symbol;
}

int Order::getQuan() const{
    return quantity;
}

OrderType Order::getType() const{
    return type;
}

