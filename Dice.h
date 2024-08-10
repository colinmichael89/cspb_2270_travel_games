#ifndef DICE_H
#define DICE_H

#include <vector>

using namespace std;

class Dice {
public:
    vector<int> roll(int numDice);

private:
    int rollSingleDie();
};

#endif // Dice.h
