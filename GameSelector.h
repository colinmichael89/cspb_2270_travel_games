#ifndef GAMESELECTOR_H
#define GAMESELECTOR_H

#include "Farkle.h"

class GameSelector {
public:
    GameSelector(); // Constructor to initialize selectedGame
    ~GameSelector(); // Destructor to clean up selectedGame

    void selectGame();
    void inputPlayers();
    void startGame();
    void displayMenu();

private:
    CircularLinkedList players;
    Game* selectedGame;
};

#endif // GAMESELECTOR_H
