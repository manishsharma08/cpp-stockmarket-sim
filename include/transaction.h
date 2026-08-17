#pragma once
#include <string>


enum class TransactionType{ // creating an enum which helps us define a new type whose only possible values are fixed
    BUY,
    SELL
};

// think of enum as a new data type (like bool , int , char ,str)

class Transaction{ //creating a class transaction which prints out whatever purchase/selling we have done
    public:
        Transaction(std::string symbol , double value , int quantity , TransactionType type);
        std::string getSymbol() const; // getter (1) -> private data needs public getters to be readable(NOT CHANGABLE)
        double getValue() const; // getter (2) [const -> so the private data doesnt change remember we are just reading]
        int getQuantity() const; // getter (3)
        TransactionType getType() const; // getter (4)
    private:
        std::string symbol;
        double value;
        int quantity;
        TransactionType type;

};