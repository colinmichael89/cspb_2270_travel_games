#ifndef DICE_H
#define DICE_H

#include <vector>

using namespace std;

class Dice {
public:
    vector<int> roll(int numDice);
    int calculateScore(const vector<int>& diceRoll);

private:
    int rollSingleDie();
};

#endif // Dice.h
