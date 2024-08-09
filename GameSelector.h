#ifndef GAMESELECTOR_H
#define GAMESELECTOR_H

#include "Farkle.h"

class GameSelector {
public:
	void selectGame();
	void inputPlayers();
	void startSelectedGame();

private:
	CircularLinkedList players;
	Game* selectedGame;
	void displayMenu() const;
};
#endif // GameSelector.h
