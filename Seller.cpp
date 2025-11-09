// FileName: Seller.cpp
#include "Seller.h"
#include <iostream>
using namespace std;

Seller::Seller(string id, string name, string email) : User(id, name, email) {}

void Seller::listProduct(shared_ptr<Product> product) {
    cout << "[Action] Seller '" << name << "' listed product: '" << product->getTitle() << "'." << endl;
}

void Seller::displayRole() const {
    cout << "Role: Seller" << endl;
}