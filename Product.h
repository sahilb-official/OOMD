// FileName: Product.h
#pragma once
#include <string>
#include <memory>
#include <vector>     // <-- ADD THIS
#include "Enums.h"
#include "IObserver.h" // <-- ADD THIS
using namespace std;

class User;

class Product {
protected:
    string productID;
    string title;
    string description;
    ProductStatus status;
    weak_ptr<User> owner;

    // A list of all observers (Bidders) watching this product
    vector<IObserver*> observers; // <-- ADD THIS

public:
    Product(string id, string title, string desc, shared_ptr<User> owner);
    virtual ~Product() = default; 

    void updateStatus(ProductStatus newStatus);
    string getTitle() const;

    virtual void displayDetails() const = 0; 

    // --- NEW OBSERVER FUNCTIONS ---
    void attach(IObserver* observer);
    void notifyObservers(double newHighestBid, const string& highBidderName);
};