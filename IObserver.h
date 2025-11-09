// FileName: IObserver.h
#pragma once
#include <string>
using namespace std;

class IObserver {
public:
    virtual ~IObserver() {} // Virtual destructor for a base class
    
    // The "contract" function.
    // We pass the winner's name so a Buyer can avoid notifying themselves.
    virtual void update(const string& productName, double newHighestBid, const string& highBidderName) = 0;
};