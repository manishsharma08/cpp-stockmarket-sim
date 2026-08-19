#include <iostream>
#include "../include/stock.h"
#include "../include/portfolio.h"
#include "../include/market.h"
#include "../include/limitorder.h"
#include "../include/marketorder.h"
#include <ctime>
#include <cstdlib>
#include <sstream>
using namespace std;



int main(){
    srand(time(0));

    Portfolio portfolio(10000);
    Market market;
    market.add("AAPL", 190.0);
    market.add("TSLA", 250.0);
    market.add("GOOG", 165.0);


    //test

    Order* order1 = new MarketOrder("AAPL",5,OrderType::BUY);
    order1->execute(portfolio,market);

    Order* order2 = new LimitOrder("TSLA",2,OrderType::SELL,100);
    order2->execute(portfolio,market);

    portfolio.viewPortfolio(market);

// making a full proper fleged working main
while(true){
    std::cout << "> ";
    std::string line;
    std::getline(std::cin,line);  // asks user for a whole line ex:- buy AAPL 10

    std::stringstream ss(line);
    std::string command; // this is where each word is stored
    std::string symbol; // stores the symbol
    int quantity;

    ss >> command;

    if(command == "quit"){
        break;
    }else if(command == "buy"){
        
        ss >> symbol >> quantity; // only pulled here since "buy" is the only command that needs a symbol/quantity
        bool success = portfolio.buyShare(symbol,quantity,market);
        if(success){
            std::cout << "Bought " << quantity << " shares of " << symbol << std::endl;
        }else{
            std::cout << "Purchase failed ----- insufficent funds." << std::endl;
        }
        
    }else if(command == "sell"){
        ss >> symbol >> quantity;
        bool success = portfolio.sellShare(symbol,quantity,market);
        if(success){
            std::cout << "Sold " << quantity << " shares of " << symbol << std::endl;
        }else{
            std::cout << "Transaction failed -- insufficent quantity to sell." << std::endl;
        }
    }else if(command == "portfolio"){
        portfolio.viewPortfolio(market);
    }
    else if(command == "market"){
        market.listStocks();
    }else if(command == "history"){
        portfolio.printHistory();
    }else if(command == "tick"){
        market.tick();
        market.listStocks();
    }
        else{
        std::cout << "Unknown command" << std::endl;
    }



    /**/


}




}