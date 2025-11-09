// FileName: Chat.h
#pragma once
#include <string>
#include <vector>
#include <memory>
#include "User.h" // Needs User
using namespace std;

class Chat {
private:
    shared_ptr<User> user1;
    shared_ptr<User> user2;
    vector<string> messages;

public:
    Chat(shared_ptr<User> u1, shared_ptr<User> u2);
    void sendMessage(string fromUser, string message);
    void displayChatHistory() const;
};