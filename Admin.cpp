// FileName: Admin.cpp
#include "Admin.h"
using namespace std;
#include <iostream>

Admin::Admin(string id, string name, string email) : User(id, name, email) {}

void Admin::approveProduct(Product& product) {
    cout << "[Action] Admin '" << name << "' approved the product: '" << product.getTitle() << "'." << endl;
    product.updateStatus(ProductStatus::AVAILABLE);
}

void Admin::displayRole() const {
    cout << "Role: Admin" << endl;
}