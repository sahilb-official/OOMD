// FileName: Transaction.h
#pragma once
#include <fstream> 
#include <memory>
#include <string>
#include "Buyer.h"
#include "Seller.h"
#include "Product.h"
#include "Enums.h"
#include "Chat.h" // <-- ADD THIS

using namespace std;

class Transaction {
private:
    string transactionID;
    shared_ptr<Buyer> buyer;
    shared_ptr<Seller> seller;
    shared_ptr<Product> product;
    double amount;
    TransactionStatus status;
    shared_ptr<Chat> chatSession; // <-- ADD THIS

public:
    Transaction(string id, shared_ptr<Buyer> b, shared_ptr<Seller> s, shared_ptr<Product> p, double amt);
    void processPayment();
    
    // Getter for the chat session
    shared_ptr<Chat> getChatSession() const; // <-- ADD THIS
};