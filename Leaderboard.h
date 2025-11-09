// FileName: Leaderboard.h
#pragma once
#include <map>
#include <string>
using namespace std;
class Leaderboard {
private:
    map<string, int> scores;
    Leaderboard(); // Private constructor
    Leaderboard(const Leaderboard&) = delete;
    Leaderboard& operator=(const Leaderboard&) = delete;

public:
    static Leaderboard& getInstance();
    void addScore(const string& userName, int points);
    void display() const;
};