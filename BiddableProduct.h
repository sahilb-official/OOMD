// FileName: BiddableProduct.h
#pragma once
#include "Product.h"
#include <iostream>
using namespace std;

class BiddableProduct : public Product {
private:
    double startingBid;

public:
    // Constructor calls the base Product constructor
    BiddableProduct(string id, string title, string desc, shared_ptr<User> owner, double bid);

    // Provide the implementation for the pure virtual function
    void displayDetails() const override;

    // Getter for its specific data
    double getStartingBid() const;
};