// FileName: Transaction.cpp
#include "Transaction.h"
#include "Leaderboard.h"
#include <iostream>
#include <fstream> 
#include <memory>  

using namespace std;

Transaction::Transaction(string id, shared_ptr<Buyer> b, shared_ptr<Seller> s, shared_ptr<Product> p, double amt)
    : transactionID(id), buyer(b), seller(s), product(p), amount(amt), status(TransactionStatus::PENDING) {}

void Transaction::processPayment() {
    cout << "[Transaction] Processing payment of $" << amount << " from " << buyer->getName() << " to " << seller->getName() << "." << endl;
    
    status = TransactionStatus::COMPLETED;
    product->updateStatus(ProductStatus::SOLD);
    
    Leaderboard::getInstance().addScore(seller->getName(), 100);
    Leaderboard::getInstance().addScore(buyer->getName(), 20);

    // --- CREATE CHAT SESSION (but don't send messages) ---
    chatSession = make_shared<Chat>(seller, buyer);

    // --- FILE HANDLING LOGIC (Unchanged) ---
    ofstream receiptFile;
    string fileName = "Receipt_" + transactionID + ".txt";
    receiptFile.open(fileName);

    if (receiptFile.is_open()) {
        receiptFile << "--- EwasteX Transaction Receipt ---\n";
        receiptFile << "=====================================\n";
        receiptFile << "Transaction ID: " << transactionID << "\n";
        receiptFile << "Product: " << product->getTitle() << "\n";
        receiptFile << "-------------------------------------\n";
        receiptFile << "Sold By: " << seller->getName() << " (ID: " << seller->getID() << ")\n";
        receiptFile << "Purchased By: " << buyer->getName() << " (ID: " << buyer->getID() << ")\n";
        receiptFile << "-------------------------------------\n";
        receiptFile << "Final Amount: $" << amount << "\n";
        receiptFile << "Status: " << "COMPLETED\n";
        receiptFile << "=====================================\n";
        receiptFile.close();
        
        cout << "[System] Transaction receipt saved to " << fileName << endl;
    } else {
        cout << "[Error] Could not save receipt file!" << endl;
    }
}

shared_ptr<Chat> Transaction::getChatSession() const {
    return chatSession;
}