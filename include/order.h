#pragma once //ensure that a file is included only once during a single compilation
#include <string>

enum class OrderType{
    BUY,
    SELL
};

class Order{
public:
    Order(std::string symbol , int quantity , OrderType type);
    std::string getSymbol() const;
    int getQuan() const;
    OrderType getType() const;
protected:
    std::string symbol;
    int quantity;
    OrderType type;
};