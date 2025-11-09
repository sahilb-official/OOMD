// FileName: User.cpp
#include "User.h"
#include <iostream>
using namespace std;


User::User(string id, string name, string email)
    : userID(id), name(name), email(email) {}

string User::getName() const {
    return name;
}

string User::getID() const {
    return userID;
}

void User::displayRole() const {
    cout << "Role: Generic User" << endl;
}