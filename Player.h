#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
public:
    Player(const string& name);

    string getName() const;
    int getScore() const;
    void addScore(int score);
    int getWins() const;
    void incrementWins();

private:
    string name;
    int totalScore;
    int turnScore;
    int wins;
};

#endif // Player.h


