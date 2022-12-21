#pragma once
#include <string>
#include "Board.hpp"
#include "Guest.hpp"
#include "Square.hpp"

constexpr int defaultPosition = 0;
constexpr Money defaultMoneyValue = 4000;

class Player : public Guest {
public:
    Player(std::string name, const Board& board);
    Player(std::string name, const Board& board, Money startingMoney);
    void move(unsigned int numOfMoves);
    std::string getName() const;

protected:
    void addMoney(Money amount) override;
    void substractMoney(Money amount) override;

private:
    int position_{defaultPosition};
    std::string playerName_;
    Money money_{defaultMoneyValue};
    const Board& board_;
};