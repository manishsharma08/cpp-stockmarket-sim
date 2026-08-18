#pragma once
#include "../include/order.h"

// MarketOrder = an order that executes immediately at the current market price, no conditions.
// Inherits shared data (symbol, quantity, type) from Order, and provides its own execute() logic.
class MarketOrder : public Order{
    public:
    MarketOrder(std::string symbol , int quantity , OrderType type);
    void execute(Portfolio& portfolio , Market& market) override;
};


