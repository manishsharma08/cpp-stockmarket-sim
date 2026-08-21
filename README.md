# Stock Market Simulator

A command-line stock market simulator written in C++. The project allows users to buy and sell stocks, place market and limit orders, view their portfolio, track transaction history, simulate market price changes, and save or load portfolio data.

## Features

- Start with an initial cash balance of `$10,000`.
- Trade stocks using their ticker symbols.
- Buy shares at the current market price.
- Sell shares from your portfolio.
- Execute market orders.
- Execute limit orders.
- View current stock prices.
- View owned shares and portfolio value.
- Track transaction history.
- Simulate stock price changes with market ticks.
- Save portfolio data to a file.
- Load previously saved portfolio data.
- Handle invalid symbols, insufficient funds, and insufficient shares.

## Available Stocks

The simulator currently starts with the following stocks:

| Symbol | Initial Price |
|---|---:|
| AAPL | $190.00 |
| TSLA | $250.00 |
| GOOG | $165.00 |

Stock prices may change when the `tick` command is used.

## Project Structure

```text
cpp-stockmarket-sim/
├── build/
├── include/
│   ├── limitorder.h
│   ├── market.h
│   ├── marketorder.h
│   ├── order.h
│   ├── portfolio.h
│   ├── stock.h
│   └── transaction.h
├── src/
│   ├── limitorder.cpp
│   ├── main.cpp
│   ├── market.cpp
│   ├── marketorder.cpp
│   ├── order.cpp
│   ├── portfolio.cpp
│   ├── stock.cpp
│   └── transaction.cpp
├── tests/
│   └── test_portfolio.cpp
├── CMakeLists.txt
├── portfolio.txt
└── README.md
```

### Header files

The `include` directory contains the declarations for the main classes:

- `stock.h` defines the stock model.
- `market.h` manages the available stocks and price updates.
- `portfolio.h` manages cash, holdings, transactions, and persistence.
- `order.h` defines the base order class and order types.
- `marketorder.h` defines market orders.
- `limitorder.h` defines limit orders.
- `transaction.h` defines transaction records.

### Source files

The `src` directory contains the implementations of the project classes:

- `main.cpp` contains the command-line interface.
- `stock.cpp` implements stock behavior.
- `market.cpp` implements market operations.
- `portfolio.cpp` implements buying, selling, displaying, saving, and loading.
- `order.cpp` implements common order functionality.
- `marketorder.cpp` implements market order execution.
- `limitorder.cpp` implements limit order execution.
- `transaction.cpp` implements transaction history functionality.

### Tests

The `tests` directory contains tests for portfolio-related functionality.

## How It Works

When the program starts, it:

1. Seeds the random number generator using the current time.
2. Creates a portfolio with `$10,000`.
3. Creates a market.
4. Adds AAPL, TSLA, and GOOG.
5. Executes example market and limit orders.
6. Displays the portfolio.
7. Starts the interactive command-line interface.

The initial example orders in `main.cpp` are:

```cpp
MarketOrder("AAPL", 5, OrderType::BUY);
LimitOrder("TSLA", 2, OrderType::SELL, 100);
```

The interactive command loop then waits for commands entered by the user.

## Commands

### Buy shares

```text
buy SYMBOL QUANTITY
```

Example:

```text
buy AAPL 10
```

This attempts to buy the specified number of shares at the current market price.

The purchase fails if:

- The stock symbol does not exist.
- The quantity is invalid.
- The portfolio does not have enough cash.

### Sell shares

```text
sell SYMBOL QUANTITY
```

Example:

```text
sell TSLA 2
```

This attempts to sell shares currently owned by the portfolio.

The sale fails if:

- The stock symbol does not exist.
- The quantity is invalid.
- The portfolio does not contain enough shares.

### View portfolio

```text
portfolio
```

Displays information such as:

- Available cash.
- Owned stocks.
- Number of shares.
- Current stock prices.
- Portfolio value.

### List market stocks

```text
market
```

Displays all stocks currently available in the market and their prices.

### View transaction history

```text
history
```

Displays previous transactions made during the session or loaded from storage.

### Simulate a market update

```text
tick
```

Updates stock prices and displays the market afterward.

Example:

```text
tick
```

This can be used to simulate changing market conditions.

### Save portfolio

```text
save
```

Saves the portfolio data to a file. The project includes `portfolio.txt` for portfolio persistence.

### Load portfolio

```text
load
```

Loads previously saved portfolio data from the portfolio file.

### Quit the program

```text
quit
```

Ends the simulation.

## Order Types

The project uses an object-oriented order system with a base `Order` class and specialized order classes.

### Market orders

A market order executes immediately using the current market price.

```cpp
MarketOrder order("AAPL", 5, OrderType::BUY);
order.execute(portfolio, market);
```

Market orders are useful when the user wants to buy or sell immediately.

### Limit orders

A limit order is executed only when its price condition is satisfied.

```cpp
LimitOrder order("TSLA", 2, OrderType::SELL, 100);
order.execute(portfolio, market);
```

The limit price determines whether the order can be executed. This allows the simulator to model conditional trading rather than executing every order immediately.

## Object-Oriented Design

The project is organized around several classes:

- `Stock` represents an individual stock and its current price.
- `Market` stores available stocks and updates their prices.
- `Portfolio` stores cash, holdings, and transaction history.
- `Order` is the base class for trading orders.
- `MarketOrder` executes trades at the current price.
- `LimitOrder` executes trades based on a specified limit price.
- `Transaction` stores information about completed trades.

Inheritance and polymorphism are used for the different order types. Both market orders and limit orders can be executed through the common `Order` interface.

## Requirements

To build and run the project, you need:

- A C++ compiler supporting C++11 or later.
- CMake.
- A terminal or command prompt.
- Git, if cloning the repository.

The project uses standard C++ libraries such as:

```cpp
<iostream>
<ctime>
<cstdlib>
<sstream>
```

## Build Instructions

### Clone the repository

```bash
git clone https://github.com/YOUR_USERNAME/cpp-stockmarket-sim.git
cd cpp-stockmarket-sim
```

Replace `YOUR_USERNAME` with your GitHub username.

### Build with CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Run the program

From the `build` directory, run the generated executable:

```bash
./stockmarket-sim
```

On Windows, the executable may be run with:

```powershell
.\stockmarket-sim.exe
```

The exact executable name depends on the target configured in `CMakeLists.txt`.

## Example Session

```text
> market
AAPL: $190
TSLA: $250
GOOG: $165

> buy AAPL 3
Bought 3 shares of AAPL

> portfolio

> tick
AAPL: $...
TSLA: $...
GOOG: $...

> sell AAPL 1
Sold 1 shares of AAPL

> history

> save
File saved !

> quit
```

## Error Handling

The program uses exceptions and return values to handle invalid operations.

For example:

- Invalid stock symbols can produce an error message.
- Buying with insufficient funds returns a failed transaction.
- Selling more shares than owned returns a failed transaction.
- Unknown commands display:

```text
Unknown command
```

Commands must be written using the expected format. For example:

```text
buy AAPL 5
sell TSLA 2
```

## Testing

Tests are located in:

```text
tests/test_portfolio.cpp
```

To build the tests, use the test configuration provided in `CMakeLists.txt`. Depending on the CMake setup, tests may be run with:

```bash
ctest
```

from inside the `build` directory.

## Future Improvements

Possible improvements include:

- Add more stocks and companies.
- Add short selling.
- Add stop-loss orders.
- Add take-profit orders.
- Add a graphical user interface.
- Add user accounts.
- Add multiple portfolios.
- Improve input validation for missing or non-numeric quantities.
- Add timestamps to transaction history.
- Store data in JSON or a database instead of a text file.
- Add charts showing stock price changes.
- Add fees, commissions, and taxes.
- Improve memory management by replacing raw pointers with smart pointers.
- Add more comprehensive automated tests.

## Disclaimer

This project is an educational stock market simulation. It does not use real-time financial data and should not be used for actual investment decisions.

## License

This project does not currently specify a license. If you want others to use, modify, or distribute the code, consider adding a license such as the MIT License.
