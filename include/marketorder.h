#pragma once
#include "../include/order.h"


class MarketOrder : public Order{
    public:
    MarketOrder(std::string symbol , int quantity , OrderType type);
    void execute(Portfolio& portfolio , Market& market) override;
};


