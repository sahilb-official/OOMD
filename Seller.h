// FileName: Seller.h
#pragma once
#include "User.h"
#include "Product.h"
using namespace std;

class Seller : public User {
public:
    Seller(string id, string name, string email);
    void listProduct(shared_ptr<Product> product);
    void displayRole() const override;
};