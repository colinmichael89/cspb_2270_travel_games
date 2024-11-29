#include "Dice.h"
#include <random>

vector<int> Dice::roll(int numDice) {
    vector<int> result;
    for (int i = 0; i < numDice; ++i) {
        result.push_back(rollSingleDie());
    }
    return result;
}

int Dice::rollSingleDie() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 6);
    return dis(gen);
}
