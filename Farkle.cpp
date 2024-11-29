#include "Farkle.h"
#include "Player.h"
#include "Node.h"
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

Farkle::Farkle(CircularLinkedList& playerList) : players(playerList) {}

void Farkle::startGame() {
    cout << "Starting Farkle game...\n";
    displayRules();

    while (true) {
        takeTurn();
        if (checkForWinner()) {
            cout << "Game over! The winner is " << players.getCurrent()->getPlayer()->getName()
                << " with a score of " << players.getCurrent()->getPlayer()->getScore() << "!\n";
            displayFinalScores();  // Display final scores for all players
            displayWinner(); 
            break;  // Exit the game loop
        }
        players.moveToNext();  // Move to the next player if no winner
    }
}

void Farkle::displayScores() const {
    Node* temp = players.getCurrent();
    do {
        Player* player = temp->getPlayer();
        cout << player->getName() << ": " << player->getScore() << endl;
        temp = temp->getNext();
    } while (temp != players.getCurrent());
}

void Farkle::takeTurn() {
    Player* player = players.getCurrent()->getPlayer();
    cout << player->getName() << "'s turn.\n";
    playTurn(player);
}

void Farkle::displayRules() const {
    cout << "Farkle rules: " << endl;
    cout << "Object : " << endl;
    cout << "Be the player with the highest score over 10,000." << endl;
    cout << "How to Play : " << endl;
    cout << "When it’s your turn, type 'roll' into the command line." << endl;
    cout << "After each roll, set aside Dice that are worth points and roll the rest of them." << endl;
    cout << "If you’re lucky enough to set aside all six Dice, you can roll them all again to" << endl;
    cout << "build your running total." << endl;
    cout << "If you cannot set aside any Dice after a roll, that’s a Farkle. You lose your running" << endl;
    cout << "total of points for that turn and play passes to the left. A Farkle could happen on" << endl;
    cout << "your first roll or when you roll the remaining Dice." << endl;
    cout << "Scoring : " << endl;
    cout << "Single 1 = 100" << endl;
    cout << "Single 5 = 50" << endl;
    cout << "Three 1s = 300" << endl;
    cout << "Three 2s = 200" << endl;
    cout << "Three 3s = 300" << endl;
    cout << "Three 4s = 400" << endl;
    cout << "Three 5s = 500" << endl;
    cout << "Three 6s = 600" << endl;
    cout << "Four of any number = 1,000" << endl;
    cout << "Five of any number = 2,000" << endl;
    cout << "Six of any number = 3,000" << endl;
    cout << "1–6 straight = 1,500" << endl;
    cout << "Three pairs = 1,500" << endl;
    cout << "Four of any number with a pair = 1,500" << endl;
    cout << "Two triplets = 2,500" << endl;
}

bool Farkle::checkForWinner() const {
    Node* temp = players.getCurrent();
    do {
        Player* player = temp->getPlayer();
        if (player->getScore() >= 10000) {
            return true;  // A player has won
        }
        temp = temp->getNext();
    } while (temp != players.getCurrent());

    return false;  // No winner yet
}

void Farkle::playTurn(Player* player) {
    int turnScore = 0;
    bool turnOver = false;
    bool initialRollComplete = false;  // Flag to track if initial roll is complete
    vector<int> keptDice;

    while (!turnOver) {
        string command;
        cout << "Type 'roll' to roll the dice: " << endl;
        cin >> command;
        cin.ignore(); // Ignore any remaining newline characters in the input buffer

        if (command != "roll") {
            cout << "Invalid command. Please type 'roll' to proceed." << endl;
            continue;
        }

        vector<int> diceRoll;
        if (!initialRollComplete) {
            diceRoll = dice.roll(6); // First roll
        }
        else {
            diceRoll = dice.roll(6 - keptDice.size()); // Roll remaining dice if not all were kept
        }

        cout << "You rolled: ";
        for (int value : diceRoll) {
            cout << value << " ";
        }
        cout << "\n";

        // Select dice to keep
        vector<int> newKeptDice = selectDiceToKeep(diceRoll);
        cout << "Kept dice: ";
        for (int value : newKeptDice) {
            cout << value << " ";
        }
        cout << "\n";

        if (newKeptDice.size() == diceRoll.size()) {
            // If all dice are kept, add their score and start over
            turnScore += calculateScore(newKeptDice); // Calculate score with all kept dice
            cout << "You kept all " << newKeptDice.size() << " dice. Your score of " << turnScore << " will be added to your final score!" << endl;

            // Start over with a new roll, kept dice should be cleared now
            keptDice.clear(); // Clear kept dice
            initialRollComplete = false; // Reset the initial roll flag
        }
        else {
            // Update kept dice
            keptDice.insert(keptDice.end(), newKeptDice.begin(), newKeptDice.end());

            // Roll the number of dice that were not kept
            vector<int> newRoll = dice.roll(6 - keptDice.size());

            // Combine the kept dice with the new dice rolled
            vector<int> allDice = keptDice;
            allDice.insert(allDice.end(), newRoll.begin(), newRoll.end());

            // Output the combined dice
            cout << "You rolled: ";
            for (int value : allDice) {
                cout << value << " ";
            }
            cout << "\n";

            // Calculate the score with all dice (kept and newly rolled)
            int score = calculateScore(allDice);
            turnScore += score;
            cout << player->getName() << " scored " << score << " points this roll." << endl;
            cout << "Total points for this turn: " << turnScore << endl;

            // End the turn
            turnOver = true;
        }
    }

    // Add the accumulated turnScore to the player's total score
    player->addScore(turnScore);
    cout << player->getName() << "'s total score after this turn: " << player->getScore() << endl;
}

vector<int> Farkle::selectDiceToKeep(const vector<int>& initialRoll) {
    vector<int> keptDice;
    // Placeholder for dice selection logic
    cout << "Select dice to keep (enter numbers separated by spaces): ";
    string input;
    getline(cin, input);
    istringstream iss(input);
    int die;
    while (iss >> die) {
        keptDice.push_back(die);
    }
    return keptDice;
}

void Farkle::displayFinalScores() const {
    Node* temp = players.getCurrent();
    do {
        Player* player = temp->getPlayer();
        cout << player->getName() << ": " << player->getScore() << endl;
        temp = temp->getNext();
    } while (temp != players.getCurrent());
}

void Farkle::displayWinner() const {
    Player* winner = players.getCurrent()->getPlayer();
    cout << "The winner is " << winner->getName() << " with a score of " << winner->getScore() << "!" << endl;
}

int Farkle::calculateScore(const vector<int>& diceRoll) const {
    unordered_map<int, int> count;
    int score = 0;

    // Count occurrences of each die value
    for (int die : diceRoll) {
        count[die]++;
    }

    // Scoring logic
    // Check for 1s
    if (count[1] >= 6) score += 3000;
    else if (count[1] == 5) score += 2000;
    else if (count[1] == 4) score += 1000;
    else if (count[1] == 3) score += 300;
    else if (count[1] == 2) score += 200;

    // Check for 5s
    if (count[5] >= 6) score += 3000;
    else if (count[5] == 5) score += 2000;
    else if (count[5] == 4) score += 1000;
    else if (count[5] == 3) score += 500;
    else if (count[5] == 2) score += 50;

    // Check for other numbers
    for (int i = 2; i <= 6; ++i) {
        if (count[i] >= 6) score += 3000;
        else if (count[i] == 5) score += 2000;
        else if (count[i] == 4) score += 1000;
        else if (count[i] == 3) {
            if (i == 2) score += 200;
            else if (i == 3) score += 300;
            else if (i == 4) score += 400;
            else if (i == 5) score += 500;
            else if (i == 6) score += 600;
        }
    }

    // Check for specific combinations
    vector<int> values = { 1, 2, 3, 4, 5, 6 };
    vector<int> counts;
    for (int value : values) {
        counts.push_back(count[value]);
    }

    // 1–6 straight
    if (counts == vector<int>(6, 1)) score += 1500;

    // Three pairs
    if (counts[0] == 2 && counts[1] == 2 && counts[2] == 2) score += 1500;

    // Four of any number with a pair
    if ((counts[0] == 4 && counts[1] == 2) ||
        (counts[1] == 4 && counts[0] == 2) ||
        (counts[2] == 4 && counts[0] == 2) ||
        (counts[3] == 4 && counts[0] == 2) ||
        (counts[4] == 4 && counts[0] == 2) ||
        (counts[5] == 4 && counts[0] == 2)) {
        score += 1500;
    }

    // Two triplets
    int tripletCount = count_if(counts.begin(), counts.end(), [](int c) { return c == 3; });
    if (tripletCount == 2) score += 2500;

    return score;
}