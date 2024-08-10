#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Player.h"

class Game {
public:
    virtual void startGame() = 0;
    virtual void takeTurn() = 0;
    virtual void displayRules() const = 0;
    virtual void displayScores() const = 0;
    virtual void displayFinalScores() const = 0;
    virtual void displayWinner() const = 0;
    virtual bool checkForWinner() const = 0;
    virtual int calculateScore(const vector<int>& diceRoll) const = 0; // Pure virtual function

    virtual ~Game() = default;
};

#endif // GAME_H
