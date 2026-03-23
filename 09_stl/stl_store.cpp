#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <ctime>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Product {
    int productID;
    string name;
    string category;
};

struct Order {
    int orderID;
    int productID;
    int quantity;
    string customerID;
    time_t orderDate;
};

int main() {
    vector<Product> products = {
        {101, "Laptop", "Electronics"},
        {102, "SmartPhone", "Electronics"},
        {103, "Coffee Maker", "Kitchen"},
        {104, "Blender", "Kitchen"},
        {105, "Desk lamp", "Home"},
    };

    deque<string> recentCustomers = {"C001", "C002", "C003"};

    recentCustomers.emplace_back("C004");
    recentCustomers.emplace_front("C005");

    list<Order> orderHistory;

    orderHistory.emplace_back(Order{1, 101, 1, "C001", time(0)});
    orderHistory.emplace_back(Order{2, 102, 2, "C002", time(0)});
    orderHistory.emplace_back(Order{3, 103, 1, "C003", time(0)});

    set<string> categories;
    for (const auto &product: products) {
        categories.insert(product.category);
    }

    map<int, int> productStock = {
        {101, 10},
        {102, 20},
        {103, 15},
        {104, 5},
        {105, 7},
    };

    multimap<string, Order> customerOrders;
    for (const auto &order: orderHistory) {
        customerOrders.insert({order.customerID, order});
    }

    unordered_map<string, string> customerData = {
        {"C001", "Alice"},
        {"C002", "Hitesh"},
        {"C003", "Vidya"},
        {"C004", "Max"},
        {"C005", "Harry"},
    };

    unordered_set<int> uniqueProductIDs;

    for (const auto &product: products) {
        uniqueProductIDs.insert(product.productID);
    }

    cout << "--- System Initialized Successfully ---\n" << endl;

    string searchCustomer = "C002";
    auto range = customerOrders.equal_range(searchCustomer);

    cout << "Orders for " << customerData[searchCustomer] << ":" << endl;
    for (auto it = range.first; it != range.second; ++it) {
        cout << "- Order ID: " << it->second.orderID 
             << " | Product ID: " << it->second.productID 
             << " | Qty: " << it->second.quantity << endl;
    }

    cout << "\nUnique Product Categories (" << categories.size() << "):" << endl;
    for(const auto &category : categories) {
        cout << "- " << category << endl;
    }

    return 0;
}
