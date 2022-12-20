#include "Player.hpp"
#include <iostream>
#include <random>

Player::Player(std::string name, const Board& board)
    : playerName_(name), board_(board) {}

void Player::move() {
    auto numberOfMoves = throwDices();
    std::cout << "    throwDices: " << numberOfMoves << "\n";
    std::cout << "    current position: " << position_ << "\n";

    while (numberOfMoves--)
    {
        position_++;
        if (position_ >= board_.getBoardSize())
        {
            position_ = 0;
        }
        std::cout << "    moving to the next position: " << position_ << "\n";
        const auto& squareInfo = board_.getSquareInfo(position_);
        squareInfo.onPass(*this);
    }
    const auto& squareInfo = board_.getSquareInfo(position_);
    squareInfo.onLand(*this);
}

void Player::addMoney(Money amount){
    money_ += amount;
}

void Player::substractMoney(Money amount){
    if (amount >= money_)
    {
        money_ = 0;
    }
    money_ -= amount;
}

std::string Player::getName() const {
    return playerName_;
}

int Player::getPosition() const {
    return position_;
}

int Player::getMoney() const {
    return money_;
}

int Player::throwDices() {
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> dice{2, 12};
    return dice(gen);
}
