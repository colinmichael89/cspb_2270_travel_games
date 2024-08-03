#ifndef FARKLE_H;
#define FARKLE_H;

#include "CircularLinkedList.h";
#include "Dice.h";

#include <vector>;
#include <string>;
#include <sstream>;

using namespace std;

class Farkle : public game { // inherit attributes and methods from base class game
public:
	void startGame() override;  // overide is used to override the base class method
	void takeTurn() override;
	void displayRules() const override;
	void displayScores() const override;
	void displayFinalScores() const override;
	void displayWinner() const override;

private:
	CircularLinkedList& players; // pass by reference to avoid copying
	Dice dice;

	void playTurn(Player* player);
	vector<int> selectDiceToKeep(const vector<int>& initialRole);
};

#endif // Farkle.h

