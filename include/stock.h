#pragma once
#include <string>

class Stock {
public:
    Stock(std::string symbol, double value);

    std::string getsymbol() const;
    double getvalue() const;
    void setprice(double newprice);

private:
    std::string symbol;
    double value;
};
