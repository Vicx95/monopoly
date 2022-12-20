#include "Player.hpp"
#include <random>

Player::Player(std::string name, const Board& board)
    : playerName_(name), board_(board) {}

void Player::move() {
    [[maybe_unused]]auto result = throwDices();
}

int Player::throwDices() {
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> dice{2, 12};
    return dice(gen);
}