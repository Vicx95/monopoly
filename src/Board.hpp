#pragma once
#include <vector>
#include <memory>
#include "Square.hpp"

constexpr int defaultBoardSize = 40;

class Board {
public:
    Board();
    Board(std::size_t size);

    const Square& getSquareInfo(int index) const;
    int getBoardSize() const;

private:
    std::vector<std::unique_ptr<Square>> board_;
};

class BoardIterator {
public:
    BoardIterator(const Board& board);
    const Square& operator++();
    const Square& getCurrent();

private:
    const Board& board_;
    int position_{0};
};