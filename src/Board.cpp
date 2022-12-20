#include "Board.hpp"

Board::Board() {
    for (unsigned int i = 0; i < board_.size(); ++i) // TODO: consider configurability
    {
        board_[i] = std::make_unique<RewardSquare>();
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

const Square& Board::getSquareInfo(int index) const {

    return *board_[index];
}

int Board::getBoardSize() const {
    return static_cast<int>(board_.size());
}