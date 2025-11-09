// FileName: DonationProduct.h
#pragma once
#include "Product.h"
#include "DonationRequest.h" // <-- ADD THIS
#include <iostream>
#include <vector> // <-- ADD THIS
using namespace std;

class DonationProduct : public Product {
private:
    // "has-a" relationship (Composition)
    vector<shared_ptr<DonationRequest>> requests; // <-- ADD THIS

public:
    DonationProduct(string id, string title, string desc, shared_ptr<User> owner);
    void displayDetails() const override;

    // --- NEW FUNCTIONS ---
    void addRequest(shared_ptr<DonationRequest> req);
    shared_ptr<Buyer> reviewAndApproveRequest(const string& sellerName);
};