#include "Board.hpp"

Board::Board() {
    board_[0] = Square(PieceType::Start);

    board_[10] = Square(PieceType::Penalty);
    board_[5] = Square(PieceType::Penalty);
    board_[7] = Square(PieceType::Penalty);
    board_[3] = Square(PieceType::Penalty);

    board_[2] = Square(PieceType::Reward);
    board_[15] = Square(PieceType::Reward);
    board_[11] = Square(PieceType::Reward);
    board_[9] = Square(PieceType::Reward);

}

Square Board::getSquareInfo(int index) const{
    return board_[index];
}

int Board::getBoardSize() const{
    return static_cast<int>(board_.size());
}