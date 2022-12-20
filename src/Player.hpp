#pragma once
#include <string>
#include "Board.hpp"
constexpr int defaultPosition = 0;
constexpr std::size_t defaultMoneyValue = 4000;

class Player {
public:
    Player(std::string name, const Board& board);
    void move();

private:
    int throwDices();
    int position_{defaultPosition};
    std::string playerName_;
    std::size_t money_{defaultMoneyValue};
    const Board& board_;
};