#ifndef GAME_H;
#define GAME_H;

#include "Player.h";

class Game {
public:
	virtual void startGame() = 0;
	virtual void takeTurn() = 0;
	virtual void displayRules() const = 0;
	virtual void displayScores() const = 0;
	virtual void displayFinalScores() const = 0;
	virtual void displayWinner() const = 0;
	virtual bool checkForWinner() const = 0;

	virtual ~Game() = default;
};

#endif // Game.h