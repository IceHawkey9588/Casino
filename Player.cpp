#include "Player.h"

Player::Player() 
    : balance(1000), wins(0), losses(0) {}

Player::Player(int initialBalance, int initialWins, int initialLosses) 
    : balance(initialBalance), wins(initialWins), losses(initialLosses) {}

int Player::getBalance() const {
    return balance;
}

int Player::getWins() const {
    return wins;
}

int Player::getLosses() const {
    return losses;
}

void Player::increaseBalance(int amount) {
    balance += amount;
}

void Player::decreaseBalance(int amount) {
    balance -= amount;
}

void Player::incrementWins() {
    wins++;
}

void Player::incrementLosses() {
    losses++;
}
