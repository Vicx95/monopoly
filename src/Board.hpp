#pragma once
#include <array>
#include "Square.hpp"

constexpr int boardSize = 40;

class Board {
public:
    Board();

    Square getSquareInfo(int index) const;
    int getBoardSize() const;

private:
    std::array<Square, boardSize> board_;
};