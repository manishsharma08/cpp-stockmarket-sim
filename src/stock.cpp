#include "../include/stock.h"
#include <iostream>

Stock::Stock(std::string sym,double val)
    : symbol(sym) , value(val){
}
// making getters
std::string Stock::getsymbol() const{
    return symbol;
}
double Stock::getvalue() const{
    return value;
}
void Stock::setprice(double newprice) {
    if(newprice>0){ // value can not be negative
        value = newprice;
    }
}