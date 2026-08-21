# C++ Stock Market Simulator

A command-line stock market simulation system built from scratch in C++ to explore object-oriented design, inheritance, polymorphism, exception handling, file persistence, testing, and modular software architecture.

The application provides a simulated market where users can view stocks, buy and sell shares, execute different order types, track transaction history, simulate market price changes, and save or restore portfolio data.

This project was developed as a practical application of C++ concepts beyond isolated programming exercises.

---

## Overview

The Stock Market Simulator models a simplified trading environment through a command-line interface.

A user begins with an initial cash balance and interacts with a simulated market through commands such as:

```text
> market
> buy AAPL 5
> sell AAPL 2
> portfolio
> history
> tick
> save
> load
> quit

## Key Features
Simulated stock market
Portfolio and cash management
Buying and selling stocks
Market orders
Limit orders
Transaction history
Simulated market price updates
Portfolio valuation
Save and load functionality
Command-line interface
Exception handling
Automated portfolio testing
CMake-based build system
Modular header/source architecture


-------------------------------------------------------------------------------


                         +----------------+
                         |     Market     |
                         +-------+--------+
                                 |
                                 |
                         +-------v--------+
                         |     Stock      |
                         +----------------+

                                 |
                                 |
                         +-------v--------+
                         |   Portfolio    |
                         +-------+--------+
                                 |
                 +---------------+---------------+
                 |                               |
          +------v------+                 +------v------+
          | Transaction |                 |    Order    |
          +-------------+                 +------+------+
                                                |
                                  +-------------+-------------+
                                  |                           |
                           +------v------+             +------v------+
                           | MarketOrder |             | LimitOrder  |
                           +-------------+             +-------------+













# **C++ Concepts Demonstrated**
Object-Oriented Programming
Classes
Objects
Encapsulation
Inheritance
Polymorphism
Virtual functions
Composition
Memory and References
Pointers
References
Object lifetime
Dynamic allocation
Standard Library
std::string
std::vector
std::stringstream
STL algorithms and containers where appropriate
Error Handling
Exceptions
try
catch
std::exception
File Handling
Reading from files
Writing to files
Persistent application state
Build and Development
Header/source separation
CMake
Git
GitHub
Automated testing