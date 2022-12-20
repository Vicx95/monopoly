#include "Square.hpp"
#include "Player.hpp"
#include <iostream>

void StartSquare::onPass(Player& player) const {
    std::cout << "    StartSquare::onPass\n";
    std::cout << "    adding 400\n";
    player.addMoney(400); // TODO: (1) change 400 to something configurable; (2) consider cases with negative amount (if possible)
}

void StartSquare::onLand([[maybe_unused]]Player& player) const {
    std::cout << "    StartSquare::onLand\n";
    // intentionally empty
}

void PenaltySquare::onPass([[maybe_unused]]Player& player) const {
    std::cout << "    PenaltySquare::onPass\n";
    // intentionally empty
}

void PenaltySquare::onLand(Player& player) const {
    std::cout << "    PenaltySquare::onLand\n";
    std::cout << "    substracting 400\n";
    player.substractMoney(400);
}

void RewardSquare::onPass([[maybe_unused]]Player& player) const {
    std::cout << "    RewardSquare::onPass\n";
    // intentionally empty
}

void RewardSquare::onLand(Player& player) const {
    std::cout << "    RewardSquare::onLand\n";
    std::cout << "    adding 1000\n";
    player.addMoney(1000);
}