#include "Square.hpp"
#include "Player.hpp"

void StartSquare::onPass(Player& player) const {
    player.addMoney(400); // TODO: change 400 to something configurable
}

void StartSquare::onLand(Player& player) const {

}

void PenaltySquare::onPass(Player& player) const {

}

void PenaltySquare::onLand(Player& player) const {

}

void RewardSquare::onPass(Player& player) const {

}

void RewardSquare::onLand(Player& player) const {

}