// FileName: Buyer.h
#pragma once
using namespace std;
#include "User.h"
#include "Product.h"
#include "IObserver.h" // <-- ADD THIS

// Buyer is now also an IObserver
class Buyer : public User, public IObserver {
public:
    Buyer(string id, string name, string email);
    void placeBid(const Product& product, double amount);
    void displayRole() const override;

    // Implementation for the IObserver interface
    void update(const string& productName, double newHighestBid, const string& highBidderName) override;
};