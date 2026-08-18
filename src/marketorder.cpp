#include "../include/marketorder.h"
// MarketOrder = a type of Order that executes immediately at the current market price.
MarketOrder::MarketOrder(std::string symbol , int quantity , OrderType type)
    : Order(symbol,quantity,type)// pass values straight to Order's constructor, since MarketOrder has nothing extra to store

{
}

void MarketOrder::execute(Portfolio& portfolio , Market& market){// performs the trade immediately, no conditions to check
    if(type == OrderType::BUY){
        portfolio.buyShare(symbol,quantity,market);// execute the buy using the inherited symbol/quantity
    }else{
        portfolio.sellShare(symbol,quantity,market);
    }
}