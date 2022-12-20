#pragma once
#include <array>
#include <memory>
#include "Square.hpp"

constexpr int boardSize = 40;

class Board {
public:
    Board();

    const Square& getSquareInfo(int index) const;
    int getBoardSize() const;

private:
    std::array<std::unique_ptr<Square>, boardSize> board_;
};