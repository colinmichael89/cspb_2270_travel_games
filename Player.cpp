#include "Player.h"

Player::Player(const string& name) : name(name), totalScore(0), turnScore(0), wins(0) {}

string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return totalScore;
}

void Player::addScore(int score) {
    totalScore += score;
}

int Player::getWins() const {
    return wins;
}

void Player::incrementWins() {
    wins++;
}
