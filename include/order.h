#pragma once //ensure that a file is included only once during a single compilation
#include <string>
#include "../include/portfolio.h"

enum class OrderType{ // enum class for the type of order
    BUY,
    SELL
};

class Order{ // defining a new class order (so we can buy stock for ex buy aapl when price is below 170$)
public:
    Order(std::string symbol , int quantity , OrderType type); 
    std::string getSymbol() const; // getters (used for extraction of the protected variables)
    int getQuan() const;
    OrderType getType() const;
    virtual void execute(Portfolio& portfolio, Market& market) = 0; 
    // virtual = allows derived classes to provide their own version of this function
    // = 0 makes it "pure virtual" -> Order has NO implementation, making Order abstract
    // (can't create a plain Order object; only MarketOrder/LimitOrder, which MUST implement this)
protected: // any inherited class can access these
    std::string symbol;
    int quantity;
    OrderType type;
};