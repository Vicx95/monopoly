#include "Player.hpp"
#include <iostream>

Player::Player(std::string name, const Board& board)
    : playerName_(name), board_(board), boardIterator_(BoardIterator(board)) {
}

Player::Player(std::string name, const Board& board, Money startingMoney)
    : playerName_(name), money_(startingMoney), board_(board), boardIterator_(BoardIterator(board)) {}

void Player::move(unsigned int numberOfMoves) {
    std::cout << "    Current position: [" << position_ << "]\n";
    std::cout << "    Current money balance: " << money_ << "\n";
    std::cout << "    Dice are thrown. Number of moves to make: " << numberOfMoves << "\n";

    while (numberOfMoves--) {
        const auto& squareInfo = ++boardIterator_;
        squareInfo.onPass(*this);
    }
    const auto& squareInfo = *boardIterator_;
    squareInfo.onLand(*this);

    std::cout << "    Money: " << money_ << "\n";
}

void Player::addMoney(Money amount) {
    money_ += amount;
}

void Player::substractMoney(Money amount) {
    if (amount >= money_) {
        money_ = 0;
    }
    money_ -= amount;
}

std::string Player::getName() const {
    return playerName_;
}
