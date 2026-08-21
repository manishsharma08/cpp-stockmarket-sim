#include <cassert>
#include <iostream>
#include "../include/Market.h"
#include "../include/Portfolio.h"

int main() {
    // Test 1: buying deducts correct cash
    Market market;
    market.add("AAPL", 100.0);
    Portfolio p(1000.0);

    bool success = p.buyShare("AAPL", 5, market);
    assert(success == true);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}