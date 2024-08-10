#ifndef FARKLE_H
#define FARKLE_H

#include "CircularLinkedList.h"
#include "Game.h"
#include "Dice.h"

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Farkle : public Game { // inherit attributes and methods from base class game
public:
    Farkle(CircularLinkedList& playerList); // constructor
    void startGame() override;  // override is used to override the base class method
    void takeTurn() override;
    void displayRules() const override;
    void displayFinalScores() const override;
    void displayWinner() const override;
    bool checkForWinner() const override;
    void displayScores() const;
    int calculateScore(const vector<int>& diceRoll) const override;

private:
    CircularLinkedList& players; // pass by reference to avoid copying
    Dice dice;

    void playTurn(Player* player);
    vector<int> selectDiceToKeep(const vector<int>& initialRoll);
};

#endif // FARKLE_H

