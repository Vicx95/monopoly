#pragma once
#include <vector>
#include "Player.hpp"

class MonopolyGame {
public:
    MonopolyGame(const std::vector<Player>& players, const Board& board);

    void startGame(int numberOfRounds);

private:
    const std::vector<Player>& players_;
    const Board& board_;
};