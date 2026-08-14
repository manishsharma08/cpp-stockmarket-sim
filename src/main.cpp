#include <iostream>
#include "../include/stock.h"
using namespace std;

int main()
{
    Stock apple("AAPL", 190.0);
    cout << apple.getsymbol() << endl;
    cout << apple.getvalue() << endl;
    apple.setprice(195.50);
    cout << apple.getvalue();
    return 0;
}