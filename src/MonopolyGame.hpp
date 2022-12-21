#pragma once
#include <vector>
#include "Player.hpp"
#include "Dice.hpp"

class MonopolyGame {
public:
    MonopolyGame(const Board& board, const Dice& dice);

    void startGame(unsigned int numberOfRounds);
    void addPlayer(const std::string& name);

private:
    void playRound();
    void takePlayerTurn(Player& player);

    std::vector<Player> players_;
    const Board& board_;
    const Dice& dice_;
};