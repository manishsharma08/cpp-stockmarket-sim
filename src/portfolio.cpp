    #include "../include/portfolio.h"
    #include <iostream>

    Portfolio::Portfolio(double startingCash) : cash(startingCash){
    }; //constructor for portfolio used for accesing cash so there is no garbage value
    // without it object data starts as random garbage

    bool Portfolio::buyShare(std::string symbol , int quantity , Market& market){ // working on the buyshare func
        Stock& s = market.getStock(symbol); // getting the symbol
        double price = s.getvalue();  // getting its value
        double cost = price * quantity; // calculating its cost

        if(cost>cash){  // user needs to have that amount of money to actually buy that stock
            return false;
        }else{
            cash -= cost; // if bought cash decreases cost times 
            holdings[symbol] += quantity; // map used to increase the quantity of stock owned
            Transaction t(symbol , price , quantity , TransactionType::BUY); // making transaction object
            history.push_back(t); // putting the object in the vectory history
            return true;
        }

    }


    bool Portfolio::sellShare(std::string symbol , int quantity, Market& market){ // sellshare function
        Stock& s = market.getStock(symbol);
        double price = s.getvalue();
        double cost = price*quantity;
        //check if user has enough shares to sell

        auto it = holdings.find(symbol); // seaches holdings for a key matching symbol
        if(it == holdings.end() || it->second < quantity){ // checks if theres nothing in the holdings or if the stock theyre trying to sell less than quan
            return false;
        }
        it->second -= quantity;
        cash += cost; // give them their money
        Transaction t(symbol , price , quantity , TransactionType::SELL); // making transaction object
        history.push_back(t); // putting the object in the vectory history
        return true;

    

    }


        void Portfolio::viewPortfolio(Market& market){
            std::cout << "Cash $: " << cash << std::endl; //prints current cash
            for(const auto& pair:holdings){  // loops through every stock user owns (same as arr but this isa map)
                std::string symbol = pair.first; // extract symbol (the key)
                int quantity = pair.second; // extract quantity (the value)

                Stock& s = market.getStock(symbol); // look up the real stock in market for the price and symb
                std::cout << symbol << std::endl; // print symb
                std::cout << "Quantity: " << quantity << std::endl; // print the value (quantity from map)
                std::cout << "Current price: " << s.getvalue() << std::endl; // print price 
                std::cout << "Value: " << (quantity*(s.getvalue())) << std::endl; // print total price / cost

            }
        }

    void Portfolio::printHistory() const{
        for(Transaction t : history){
            if(t.getType() == TransactionType::BUY){
                std::cout << "BUY ";
            }else{
                std::cout << "SELL ";
            }
            std::cout << t.getSymbol() << " ";
            std::cout << t.getQuantity() << " ";
            std::cout << t.getValue() << std::endl;
        }
    }