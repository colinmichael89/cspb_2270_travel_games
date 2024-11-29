#include "GameSelector.h"
#include <iostream>
#include <sstream>

using namespace std;

GameSelector::GameSelector() : selectedGame(nullptr) {}

GameSelector::~GameSelector() {
    if (selectedGame) {
        delete selectedGame;
    }
}

void GameSelector::selectGame() {
    cout << "Select a game:\n";
    cout << "1. Farkle\n";
    // Add other games here if you have more options

    int choice;
    cout << "Enter the number of your choice: ";
    cin >> choice;
    cin.ignore(); // To ignore any leftover newline characters in the input buffer

    if (selectedGame) {
        delete selectedGame;
    }

    switch (choice) {
    case 1:
        selectedGame = new Farkle(players);
        break;
        // Add cases for other games here
    default:
        cout << "Invalid choice. Please select a valid game.\n";
        selectedGame = nullptr;
        break;
    }
}

void GameSelector::inputPlayers() {
    if (!selectedGame) {
        cout << "No game selected. Please select a game first.\n";
        return;
    }

    int numPlayers;
    cout << "Enter number of players: ";
    cin >> numPlayers;
    cin.ignore(); // To ignore any leftover newline characters in the input buffer

    players = CircularLinkedList(); // Clear existing players

    for (int i = 0; i < numPlayers; ++i) {
        string playerName;
        cout << "Enter name for player " << (i + 1) << ": ";
        getline(cin, playerName);
        Player* player = new Player(playerName);
        players.addPlayer(player);
    }
}

void GameSelector::startGame() {
    if (selectedGame) {
        selectedGame->startGame();
    }
    else {
        cout << "No game selected. Please select a game first.\n";
    }
}

void GameSelector::displayMenu() {
    selectGame(); // Prompt for game selection
    inputPlayers(); // Prompt for player input
    startGame(); // Start the selected game
}
