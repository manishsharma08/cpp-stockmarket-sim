#include <string>
#pragma once
#include <unordered_map>
#include "../include/market.h"
#include "../include/transaction.h"
#include <vector>



class Portfolio // class that tracks your cash and holdings and does the actual buying and selling
{
public:
    bool buyShare(std::string symbol, int quantity, Market &market);
    // using market as paramater so we can look up the price from the stock and confirm purchase
    bool sellShare(std::string symbol, int quantity, Market &market);
    // same as buy share but it sells share
    void viewPortfolio(Market &market);
    // prints cash and every stock held, using market to look up each stock's current price and calculate value
    void printHistory() const;
    //prints history of transactions
    Portfolio(double startingCash); // constructor - sets up a new portfolio with a starting amount of cash
private:
    double cash;                                   // value of stock
    std::unordered_map<std::string, int> holdings; // dictionary so show number of shares
    std::vector<Transaction> history; // vector to show history of all our purchases/sells
};