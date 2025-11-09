// FileName: ProductFactory.h
#pragma once
#include "Product.h"
#include "BiddableProduct.h" // <-- ADD THIS
#include "DonationProduct.h" // <-- ADD THIS
#include "User.h"
#include <memory>
#include <string>
using namespace std;

class ProductFactory {
public:
    // The signature stays the same, returning a base class pointer
    static shared_ptr<Product> createProduct(const string& id, const string& title, const string& desc, shared_ptr<User> owner);
};