// FileName: BiddableProduct.cpp
#include "BiddableProduct.h"

// Use an initializer list to call the base class constructor
BiddableProduct::BiddableProduct(string id, string title, string desc, shared_ptr<User> owner, double bid)
    : Product(id, title, desc, owner), startingBid(bid) {}

void BiddableProduct::displayDetails() const {
    cout << "  - Product ID: " << productID << ", Title: " << title << endl;
    cout << "  - Type: Biddable Item" << endl;
    cout << "  - Description: " << description << endl;
    cout << "  - Starting Bid: $" << startingBid << endl;
}

double BiddableProduct::getStartingBid() const {
    return startingBid;
}