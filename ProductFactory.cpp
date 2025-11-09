// FileName: ProductFactory.cpp
#include "ProductFactory.h"
#include <iostream>
#include <limits>
using namespace std;

shared_ptr<Product> ProductFactory::createProduct(const string& id, const string& title, const string& desc, shared_ptr<User> owner) {
    
    int choice = 0;
    cout << "What type of listing is this?" << endl;
    cout << "  1. Biddable Item" << endl;
    cout << "  2. Donation Item" << endl;
    cout << "Enter choice (1 or 2): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    if (choice == 1) {
        double bid;
        cout << "Enter starting bid amount: $";
        cin >> bid;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << "[Factory] Creating new Biddable Product: " << title << endl;
        return make_shared<BiddableProduct>(id, title, desc, owner, bid);
    } else {
        cout << "[Factory] Creating new Donation Product: " << title << endl;
        return make_shared<DonationProduct>(id, title, desc, owner);
    }
}