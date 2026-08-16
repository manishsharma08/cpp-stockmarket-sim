#include <iostream>
#include "../include/stock.h"
#include "../include/portfolio.h"
#include "../include/market.h"
using namespace std;

int main()
{
    /*Stock apple("AAPL", 190.0);
    cout << apple.getsymbol() << endl;
    cout << apple.getvalue() << endl;
    apple.setprice(195.50);
    cout << apple.getvalue();
    return 0;*/

    Market market;
    market.add("TSLA", 184);
    market.add("SMSUNG", 177.9);
    market.add("NVDIA", 196);
    /*market.listStocks();
    Stock &t = market.getStock("TSLA");
    t.setprice(999);
    cout << t.getsymbol() << " " << t.getvalue();*/

    Portfolio portfolio(10000);
    portfolio.buyShare("TSLA",2,market);
    portfolio.viewPortfolio(market);
    portfolio.sellShare("TSLA",1,market);
    portfolio.viewPortfolio(market);


}