// FileName: Admin.h
#pragma once
using namespace std;
#include "User.h"
#include "Product.h"

class Admin : public User {
public:
    Admin(string id, string name, string email);
    void approveProduct(Product& product);
    void displayRole() const override;
};