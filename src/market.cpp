#include "../include/market.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <ctime>
#include <cstdlib>



void Market::add(std::string symbol, double value) // function to add new stocks
{
    Stock newstock(symbol, value); // create a new stock from giver symbol & value
    stocks.push_back(newstock);    // add the new stock to the market's vector of stocks
}

void Market::listStocks() // function to listout/print out all the stocks
{
    for (int i = 0; i < stocks.size(); i++)
    {
        std::cout << stocks[i].getsymbol() << " " << stocks[i].getvalue() << std::endl;
        // prints out all the stocks sitting inside the vector
    }
}

Stock &Market::getStock(std::string symbol) // function to print out a specific stock
{                                           //   ^---------> this here means referencing to a stock and not making another copy
    for (int i = 0; i < stocks.size(); i++)
    {
        if (stocks[i].getsymbol() == symbol) // if the symbol we entered in getstock is equal to the symbol inside the stock vector
        // then print that stock (FULL)
        {
            return stocks[i];
        }
    }
    throw std::runtime_error("Stock not found: " + symbol);
    // if no stock matched after checking the whole vector, stop and report an error instead of
    // returning garbage
}

void Market::tick(){ // function that keeps changing the values of stocks (making it random)
    for(int i = 0;i<stocks.size();i++){
        double currentprice = stocks[i].getvalue();
        double changeperc = (rand() % 21 - 10) / 100.0; //-10% to 10%
        double newprice = currentprice+ changeperc;
        stocks[i].setprice(newprice);
    }
}