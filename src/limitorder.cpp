#include "../include/limitorder.h"

LimitOrder::LimitOrder(std::string symbol , int quantity , OrderType type , double TargetPrice)
    : Order(symbol,quantity,type), Targetprice(TargetPrice)
    // pass shared fields to Order's constructor, initialize Targetprice separately
{
}


void LimitOrder::execute(Portfolio& portfolio , Market& market){ // checks condition, only trades if the price target is met
    Stock& s = market.getStock(symbol); // look up real stock and checck its current price
    double currentprice = s.getvalue(); // extract that current price

    if(type == OrderType::BUY){ // is this order a buy?
        if(currentprice<=Targetprice){ // only buy if price has dropped to or below target
            portfolio.buyShare(symbol,quantity,market); // buy
        }
    }else{ // or a sell?
        if(currentprice >= Targetprice){ // sell only if price is above target
            // sell when price reaches 200$
            portfolio.sellShare(symbol,quantity,market); //sell
        }
    }
}