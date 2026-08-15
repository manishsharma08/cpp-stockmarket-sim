#pragma once
#include <string>
#include <vector>
#include "../include/stock.h"

class Market
{
private:
    std::vector<Stock> stocks; // creating a vector called stocks which will stock the number of stocks
    // why vector -> vector is an expandable array.

public:
    void add(std::string symbol, double value);
    // a function that adds stocks ex stock.add("apple",190) [symbol and val]
    Stock getStock(std::string symbol);
    void listStocks();
};