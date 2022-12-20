#include "Square.hpp"

Square::Square(PieceType pieceType)
    : pieceType_(pieceType) {}

PieceType Square::getPieceType() const {
    return pieceType_;
}