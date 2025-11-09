// FileName: User.h
#pragma once
#include <string>
using namespace std;

class User {
protected:
    string userID;
    string name;
    string email;

public:
    User(string id, string name, string email);
    virtual ~User() = default; // Virtual destructor for polymorphism

    string getName() const;
    string getID() const;
    virtual void displayRole() const;
};