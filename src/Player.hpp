#pragma once
#include <string>
#include "Board.hpp"
#include "Square.hpp"

using Money = unsigned int;

constexpr int defaultPosition = 0;
constexpr std::size_t defaultMoneyValue = 4000;

class Player {
public:
    Player(std::string name, const Board& board);
    void move(unsigned int numOfMoves);
    void addMoney(Money amount);
    void substractMoney(Money amount);

    std::string getName() const;

private:
    int position_{defaultPosition};
    std::string playerName_;
    Money money_{defaultMoneyValue};
    const Board& board_;
};