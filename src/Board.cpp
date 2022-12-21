#include "Board.hpp"

Board::Board() {
    // create Board with default size
    board_.reserve(defaultBoardSize);
    for (unsigned int i = 0; i < defaultBoardSize; ++i) {
        board_.push_back(std::make_unique<RewardSquare>());
    }

    board_[0] = std::make_unique<StartSquare>();
    board_[3] = std::make_unique<PenaltySquare>();
    board_[4] = std::make_unique<PenaltySquare>();
    board_[5] = std::make_unique<PenaltySquare>();
    board_[7] = std::make_unique<PenaltySquare>();
    board_[9] = std::make_unique<PenaltySquare>();
    board_[10] = std::make_unique<PenaltySquare>();
    board_[11] = std::make_unique<PenaltySquare>();
    board_[15] = std::make_unique<PenaltySquare>();
}

Board::Board(std::size_t size) {
    board_.reserve(size);
    board_.push_back(std::make_unique<StartSquare>());

    for (unsigned int i = 1; i < size; ++i) {
        if (i % 2 == 0) {
            board_.push_back(std::make_unique<PenaltySquare>());
        } else {
            board_.push_back(std::make_unique<RewardSquare>());
        }
    }
}

const Square& Board::getSquareInfo(int index) const {
    return *board_[index];
}

int Board::getBoardSize() const {
    return static_cast<int>(board_.size());
}

BoardIterator::BoardIterator(const Board& board)
    : board_(board) {
}

const Square& BoardIterator::operator++() {
    position_++;
    if (position_ >= board_.getBoardSize()) {
        position_ = 0;
    }
    return board_.getSquareInfo(position_);
}

const Square& BoardIterator::operator*() {
    return board_.getSquareInfo(position_);
}