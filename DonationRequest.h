// FileName: DonationRequest.h
#pragma once
#include <string>
#include <memory>
#include "Buyer.h" // Needs Buyer
using namespace std;

class DonationRequest {
public:
    shared_ptr<Buyer> requester;
    string justification;

    // Simple constructor
    DonationRequest(shared_ptr<Buyer> req, string just)
        : requester(req), justification(just) {}
};