cmake_minimum_required(VERSION 3.16)
project(StockMarketSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(stock_sim 
    src/main.cpp 
    src/Stock.cpp 
    src/Market.cpp 
    src/Portfolio.cpp 
    src/Transaction.cpp 
    src/Order.cpp 
    src/MarketOrder.cpp 
    src/LimitOrder.cpp
)