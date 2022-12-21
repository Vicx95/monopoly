#include "MonopolyGame.hpp"
#include <iostream>
MonopolyGame::MonopolyGame(
    const Board& board,
    const Dice& dice)
    : board_(board),
      dice_(dice) {}

void MonopolyGame::startGame(unsigned int numberOfRounds) {
    std::cout << "### MONOPOLY ### \n";
    for (unsigned int i = 1; i <= numberOfRounds; ++i) {
        std::cout << "\nStarting ROUND number: " << i << '\n';
        playRound();
    }
}

void MonopolyGame::playRound() {
    for (auto& player : players_) {
        std::cout << "  Player " << player.getName() << " turn\n";
        takePlayerTurn(player);
    }
}

void MonopolyGame::takePlayerTurn(Player& player) {
    auto numOfMoves = dice_.getRolledValue();
    player.move(numOfMoves);
}

void MonopolyGame::addPlayer(const std::string& name) {
    Player newPlayer(name, board_);
    players_.push_back(newPlayer);
}