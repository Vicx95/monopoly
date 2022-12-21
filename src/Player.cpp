#include "Player.hpp"
#include <iostream>

Player::Player(std::string name, const Board& board)
    : playerName_(name), board_(board) {}

void Player::move(unsigned int numberOfMoves) {
    std::cout << "    Current position: [" << position_ << "]\n";
    std::cout << "    Current money balance: " << money_ << "\n";
    std::cout << "    Dice are thrown. Number of moves to make: " << numberOfMoves << "\n";

    while (numberOfMoves--) {
        position_++;
        if (position_ >= board_.getBoardSize()) {
            position_ = 0;
        }
        std::cout << "    Moving towards position [" << position_ << "] ";
        const auto& squareInfo = board_.getSquareInfo(position_);
        squareInfo.onPass(*this);
    }
    std::cout << "    ";
    const auto& squareInfo = board_.getSquareInfo(position_);
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

