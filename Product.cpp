// FileName: Product.cpp
#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(string id, string title, string desc, shared_ptr<User> owner)
    : productID(id), title(title), description(desc), owner(owner), status(ProductStatus::AWAITING_APPROVAL) {}

void Product::updateStatus(ProductStatus newStatus) {
    this->status = newStatus;
}

string Product::getTitle() const {
    return title;
}

// --- NEW OBSERVER FUNCTIONS ---

void Product::attach(IObserver* observer) {
    // Adds a new observer (a Buyer) to the notification list
    observers.push_back(observer);
}

void Product::notifyObservers(double newHighestBid, const string& highBidderName) {
    cout << "[Product] Notifying all " << observers.size() << " bidders of the new high bid..." << endl;
    // Loop through all observers and call their update() method
    for (IObserver* obs : observers) {
        obs->update(title, newHighestBid, highBidderName);
    }
}