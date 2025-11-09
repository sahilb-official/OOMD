// FileName: main.cpp
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

#include "Seller.h"
#include "Buyer.h"
#include "Admin.h"
#include "ProductFactory.h"
#include "Transaction.h"
#include "Leaderboard.h"
#include "BiddableProduct.h" 
#include "DonationProduct.h"
#include "DonationRequest.h" 
#include "Chat.h"            

// A simple structure to hold bid information together
struct BidInfo {
    double amount;
    shared_ptr<Buyer> bidder;
};

// --- NEW FUNCTION TO MANUALLY RUN CHAT ---
void runChatSimulation(shared_ptr<User> user1, shared_ptr<User> user2, shared_ptr<Chat> chat) {
    cout << "\n--- Pickup/Delivery Coordination Chat Started ---" << endl;
    cout << "Type 'exit' as your message to end the chat." << endl;
    string msg;

    while (true) {
        // User 1 (Seller) types
        cout << user1->getName() << " (Seller): ";
        getline(cin, msg);
        if (msg == "exit") break;
        chat->sendMessage(user1->getName(), msg);

        // User 2 (Buyer) types
        cout << user2->getName() << " (Buyer): ";
        getline(cin, msg);
        if (msg == "exit") break;
        chat->sendMessage(user2->getName(), msg);
    }

    cout << "\n--- Chat Ended ---" << endl;
    chat->displayChatHistory();
}


// --- MODIFIED BIDDING AUCTION ---
void runBiddingAuction(shared_ptr<Product> product, shared_ptr<Seller> seller) {
    
    cout << "\n--- Product '" << product->getTitle() << "' is now open for bidding! ---\n" << endl;
    vector<BidInfo> bids;
    char anotherBidder = 'y';
    int buyerCounter = 0;
    shared_ptr<Buyer> winningBuyer = nullptr;
    double winningAmount = 0.0;

    while (anotherBidder == 'y' || anotherBidder == 'Y') {
        buyerCounter++;
        string buyerName;
        double bidAmount;

        cout << "\nEnter details for Bidder #" << buyerCounter << ":" << endl;
        cout << "  Name: ";
        getline(cin, buyerName);
        cout << "  Bid Amount: $";
        cin >> bidAmount;

        auto currentBuyer = make_shared<Buyer>("B00" + to_string(buyerCounter), buyerName, buyerName + "@email.com");
        product->attach(currentBuyer.get());
        bids.push_back({bidAmount, currentBuyer});
        currentBuyer->placeBid(*product, bidAmount);

        auto highBidIt = max_element(bids.begin(), bids.end(), 
            [](const BidInfo& a, const BidInfo& b) { return a.amount < b.amount; });
        
        winningAmount = highBidIt->amount;
        winningBuyer = highBidIt->bidder;

        product->notifyObservers(winningAmount, winningBuyer->getName());

        cout << "\nIs there another bidder? (y/n): ";
        cin >> anotherBidder;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    if (bids.empty()) {
        cout << "\nNo bids were placed. The auction ends." << endl;
        return;
    }
    
    cout << "\n--- Bidding is closed! ---" << endl;
    cout << "The winning bid is $" << winningAmount << " from " << winningBuyer->getName() << "!" << endl;

    cout << "\n--- Seller accepts the winning bid, creating transaction ---" << endl;
    string newTransactionID = "Receipt_for_" + product->getTitle(); 
    Transaction transaction(newTransactionID, winningBuyer, seller, product, winningAmount);
    transaction.processPayment(); // This creates the receipt and chat object

    // --- MANUALLY START CHAT ---
    runChatSimulation(seller, winningBuyer, transaction.getChatSession());
}

// --- MODIFIED DONATION REQUEST ---
void runDonationRequest(shared_ptr<Product> product, shared_ptr<Seller> seller) {
    cout << "\n--- Product '" << product->getTitle() << "' is a DONATION item. ---\n" << endl;
    
    auto donationProduct = dynamic_pointer_cast<DonationProduct>(product);
    if (!donationProduct) return; 

    char anotherRequester = 'y';
    int reqCounter = 0;

    while (anotherRequester == 'y' || anotherRequester == 'Y') {
        reqCounter++;
        string buyerName, justification;

        cout << "\nEnter details for Requester #" << reqCounter << ":" << endl;
        cout << "  Name: ";
        getline(cin, buyerName);
        cout << "  Justification (why do you need this item?): ";
        getline(cin, justification);

        auto currentBuyer = make_shared<Buyer>("B00" + to_string(reqCounter), buyerName, buyerName + "@email.com");
        auto request = make_shared<DonationRequest>(currentBuyer, justification);
        donationProduct->addRequest(request);

        cout << "\nIs there another requester? (y/n): ";
        cin >> anotherRequester;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // --- MANUALLY REVIEW AND APPROVE ---
    shared_ptr<Buyer> winner = donationProduct->reviewAndApproveRequest(seller->getName());

    if (winner) {
        // --- MANUALLY START CHAT ---
        // A donation doesn't have a transaction, so we create the chat directly.
        auto chat = make_shared<Chat>(seller, winner);
        runChatSimulation(seller, winner, chat);
    }
}


// --- MAIN FUNCTION (Unchanged) ---
int main() {
    cout << "============== EWasteX System Simulation Started ==============\n" << endl;
    string sellerName, adminName, productTitle, productDesc;
    cout << "--- System Setup ---" << endl;
    cout << "Enter Seller's Name: ";
    getline(cin, sellerName);
    cout << "Enter Admin's Name: ";
    getline(cin, adminName);
    cout << "\nEnter Product Title for Seller '" << sellerName << "' to list: ";
    getline(cin, productTitle);
    cout << "Enter Product Description: ";
    getline(cin, productDesc);
    cout << endl;

    auto seller = make_shared<Seller>("S001", sellerName, "seller@email.com");
    auto admin = make_shared<Admin>("A001", adminName, "admin@ewastex.com");
    auto product = ProductFactory::createProduct("P101", productTitle, productDesc, seller);
    
    seller->listProduct(product);
    admin->approveProduct(*product);

    auto biddableProduct = dynamic_pointer_cast<BiddableProduct>(product);
    if (biddableProduct) {
        runBiddingAuction(product, seller);
    } else {
        runDonationRequest(product, seller);
    }

    Leaderboard::getInstance().display();
    cout << "=============== EWasteX System Simulation Ended ===============\n" << endl;
    return 0;
}