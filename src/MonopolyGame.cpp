#include "MonopolyGame.hpp"
#include <iostream>
MonopolyGame::MonopolyGame(std::vector<Player>& players, const Board& board)
    : players_(players), board_(board) {}

void MonopolyGame::startGame([[maybe_unused]] int numberOfRounds) {
    for (int i = 1; i <= numberOfRounds; ++i) {
        std::cout << "Round: " << i << '\n';
        for(auto& player : players_){
            std::cout << "Player " << player.getName() << " move\n";
        }
    }
}