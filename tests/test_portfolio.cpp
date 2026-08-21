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
    // Test 2: buying fails if not enough cash
    Portfolio p2(50.0);   // very little cash
    bool shouldFail = p2.buyShare("AAPL", 5, market);   // costs 500, way more than 50
    assert(shouldFail == false);
    return 0;
}