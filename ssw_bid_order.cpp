#include<iostream>
#include<map>
#include<string>
using namespace std;

class ticker {
    int orderid; 
    String side; 
    int quantity; 
    float price;
    public:
    ticker(int id, string side, double price, int quantity):override(id), side(side), quantity(quantity), price(price) {}
};

class OrderBook{
        private: 
            //Bid orders(price descending)
            map<double,  int> bids;
            //Ask orders(price ascending)
            map< double, int> asks;
            map <int id, ticker> orders;
        public:
            add_order(int id, string side, double price, int quantity) {
                ticker order(id, side, quantity, price);

                if (side == "Add") {
                    bids[price] += quantity;
                } else if (side == "Ask") {
                    asks[price] += quantity;
                }
                orders[id] = order;
                std::cout << "Order #" << id << " added: " << side << " " << quantity << " @ " << price << std::endl;
            }

            cancel_order(int id) {
                auto it = orders.find(id);
                 if (it == orders.end()) {
                    std::cerr << "Error: Order ID #" << id << " not found." << std::endl;
                    return;
                }

                double price = it->price;
                int quantity = it->quantity;
                string side = it->side;
                if (side == "Bid") {
                    bids[price] -= quantity;
                    if (bids[price] <= 0) {
                        bids.erase(price);
                    }
                } else if (side == "Ask") {
                    asks[price] -= quantity;
                    if (asks[price] <= 0) {
                        asks.erase(price);
                    }
                }
                orders.erase(it);
                std::cout << "Order #" << id << " cancelled." << std::endl;
            }
            // Print the order book
            void printOrderBook() const {
                std::cout << "Order Book" << std::endl;
                std::cout << "---------------------------" << std::endl;
                std::cout << "Bid (Buy)   |   Ask (Sell)" << std::endl;
                std::cout << "------------+--------------" << std::endl;

                auto bidIt = bids.begin();
                auto askIt = asks.begin();

                while (bidIt != bids.end() || askIt != asks.end()) {
                    if (bidIt != bids.end()) {
                        std::cout << std::setw(4) << bidIt->second << " @ " << std::fixed << std::setprecision(1) << bidIt->first;
                        bidIt++;
                    } else {
                        std::cout << "            ";
                    }

                    std::cout << " | ";

                    if (askIt != asks.end()) {
                        std::cout << std::setw(4) << askIt->second << " @ " << std::fixed << std::setprecision(1) << askIt->first;
                        askIt++;
                    }

                    std::cout << std::endl;
                }
            }            
};

int main() {
    OrderBook ob;
     // Add operations
    ob.addOrder(16, "Bid", 80, 99.6);
    ob.addOrder(17, "Ask", 70, 100.5);
    ob.addOrder(18, "Bid", 110, 99.3);

    // Print the order book
    ob.printOrderBook();

    // Cancel an order
    ob.cancelOrder(17);

    // Print the order book again
    ob.printOrderBook();
    return 0;
}