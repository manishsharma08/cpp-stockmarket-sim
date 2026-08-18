#pragma once
#include "../include/order.h"

//an order that executes as soon as the price reaches target price
// ex buy AAPL WHEN 170 $ or less
class LimitOrder : public Order{
public:
    LimitOrder(std::string symbol , int quantity , OrderType type, double Targetprice);
    void execute(Portfolio& portfolio , Market& market) override;
private:
    double Targetprice; // private because there are no children to grant special access to
};