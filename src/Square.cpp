#include "Square.hpp"
#include "Guest.hpp"
#include <iostream>

void printInfo([[maybe_unused]]Guest& player, std::string info)
{
    std::cout << "Player " << info << "\n";
}

void StartSquare::onPass(Guest& player) const {
    printInfo(player, "is passing START Square");
    player.addMoney(400); // TODO: (1) change 400 to something configurable; (2) consider cases with negative amount (if possible)
}

void StartSquare::onLand(Guest& player) const {
    printInfo(player, "has landed on START Square");
}

void PenaltySquare::onPass([[maybe_unused]]Guest& player) const {
    printInfo(player, "is passing PENALTY Square");
}

void PenaltySquare::onLand(Guest& player) const {
    printInfo(player, "has landed on PENALTY Square");
    player.substractMoney(400);
}

void RewardSquare::onPass([[maybe_unused]]Guest& player) const {
    printInfo(player, "is passing REWARD Square");
}

void RewardSquare::onLand(Guest& player) const {
    printInfo(player, "has landed on REWARD Square");
    player.addMoney(1000);
}