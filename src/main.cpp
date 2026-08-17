#include <iostream>
#include "../include/stock.h"
#include "../include/portfolio.h"
#include "../include/market.h"
#include <sstream>
using namespace std;

int main(){

    Portfolio portfolio(10000);
    Market market;
    market.add("AAPL", 190.0);
    market.add("TSLA", 250.0);
    market.add("GOOG", 165.0);
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
    }else{
        std::cout << "Unknown command" << std::endl;
    }
}

}