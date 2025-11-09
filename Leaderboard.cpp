// FileName: Leaderboard.cpp
#include "Leaderboard.h"
#include <iostream>
using namespace std;
Leaderboard::Leaderboard() {} // Constructor definition

Leaderboard& Leaderboard::getInstance() {
    static Leaderboard instance;
    return instance;
}

void Leaderboard::addScore(const string& userName, int points) {
    scores[userName] += points;
    cout << "[Leaderboard] Added " << points << " points to " << userName << "." << endl;
}

void Leaderboard::display() const {
    cout << "\n--- LEADERBOARD ---" << endl;
    if (scores.empty()) {
        cout << "No scores yet." << endl;
    }
    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << " points" << endl;
    }
    cout << "-------------------\n" << endl;
}