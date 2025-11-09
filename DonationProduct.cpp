// FileName: DonationProduct.cpp
#include "DonationProduct.h"
#include "Buyer.h" 
#include <iostream>
#include <limits> // For clearing input buffer
using namespace std;

DonationProduct::DonationProduct(string id, string title, string desc, shared_ptr<User> owner)
    : Product(id, title, desc, owner) {}

void DonationProduct::displayDetails() const {
    cout << "  - Product ID: " << productID << ", Title: " << title << endl;
    cout << "  - Type: Donation Item" << endl;
    cout << "  - Description: " << description << endl;
    cout << "  - Status: Available for Request" << endl;
}

void DonationProduct::addRequest(shared_ptr<DonationRequest> req) {
    requests.push_back(req);
    cout << "[System] New request for '" << title << "' has been submitted." << endl;
}

// --- HEAVILY MODIFIED FUNCTION ---
shared_ptr<Buyer> DonationProduct::reviewAndApproveRequest(const string& sellerName) {
    cout << "\n--- " << sellerName << " is reviewing " << requests.size() << " donation request(s) for '" << title << "' ---" << endl;
    
    if (requests.empty()) {
        cout << "[System] No requests were submitted for this item." << endl;
        return nullptr; // No winner
    }

    // 1. List all requests with a number
    int counter = 1;
    for (const auto& req : requests) {
        cout << "  [" << counter << "] Requester: " << req->requester->getName() << endl;
        cout << "     Justification: '" << req->justification << "'" << endl;
        counter++;
    }

    // 2. Prompt the Seller to make a choice
    int choice = 0;
    cout << "\nEnter the number to approve (1-" << requests.size() << ", or 0 to decline all): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    // 3. Process the choice
    if (choice > 0 && choice <= requests.size()) {
        // User picked a valid request (adjust for 0-based index)
        auto winner = requests[choice - 1]; 
        
        cout << "\n[System] " << sellerName << " has approved the request from " << winner->requester->getName() << "!" << endl;
        updateStatus(ProductStatus::DONATED);
        
        return winner->requester; // Return the winning buyer
    } else {
        // User entered 0 or an invalid number
        cout << "\n[System] " << sellerName << " has declined all requests for now." << endl;
        return nullptr; // No winner
    }
}