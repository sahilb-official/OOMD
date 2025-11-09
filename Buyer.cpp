// FileName: Buyer.cpp
#include "Buyer.h"
#include <iostream>
using namespace std;

Buyer::Buyer(string id, string name, string email) : User(id, name, email) {}

void Buyer::placeBid(const Product& product, double amount) {
    cout << "[Action] Buyer '" << name << "' placed a bid of $" << amount << " on '" << product.getTitle() << "'." << endl;
}

void Buyer::displayRole() const {
    cout << "Role: Buyer" << endl;
}

// --- NEW OBSERVER FUNCTION ---

void Buyer::update(const string& productName, double newHighestBid, const string& highBidderName) {
    // Check if this buyer is the one who placed the high bid. If so, don't notify them.
    if (this->name != highBidderName) {
        cout << "\n[Notification for " << this->name << "]" << endl;
        cout << "  > The auction for '" << productName << "' has a new high bid: $" << newHighestBid << endl;
        cout << "  > Placed by: " << highBidderName << endl;
    }
}