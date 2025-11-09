// FileName: Chat.cpp
#include "Chat.h"
#include <iostream>
using namespace std;

Chat::Chat(shared_ptr<User> u1, shared_ptr<User> u2)
    : user1(u1), user2(u2) {
    cout << "[System] Chat session created between " << u1->getName() << " and " << u2->getName() << "." << endl;
}

void Chat::sendMessage(string fromUser, string message) {
    // In a real app, you'd check if fromUser is user1 or user2
    messages.push_back(fromUser + ": " + message);
}

void Chat::displayChatHistory() const {
    cout << "\n--- Chat History (" << user1->getName() << "/" << user2->getName() << ") ---" << endl;
    for (const string& msg : messages) {
        cout << msg << endl;
    }
    cout << "---------------------------------" << endl;
}