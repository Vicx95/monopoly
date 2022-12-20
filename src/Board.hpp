#pragma once
#include <array>
#include "Square.hpp"

constexpr std::size_t boardSize = 40;

class Board {
public:
    Board();

private:
    std::array<Square, boardSize> board_;
};