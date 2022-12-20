#include "Player.hpp"
#include <iostream>
#include <random>

Player::Player(std::string name, const Board& board)
    : playerName_(name), board_(board) {}

void Player::move() {
    const auto numberOfMoves = throwDices();
    std::cout << "    throwDices: " << numberOfMoves << "\n";

    auto newPosition = numberOfMoves + position_;
    if (newPosition > board_.getBoardSize() - 1) {
        newPosition = newPosition - board_.getBoardSize();
    }

    std::cout << "    current position: " << newPosition << "\n";
    std::cout << "    new position: " << newPosition << "\n";

    for (int i = position_ + 1; i != newPosition; ++i)
    {
        if (i >= board_.getBoardSize())
        {
            i = 0;
        }
        const auto& squareInfo = board_.getSquareInfo(position_);
        squareInfo.onPass(*this);
    }
    const auto& squareInfo = board_.getSquareInfo(newPosition);
    squareInfo.onLand(*this);

    position_ = newPosition;
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
