#include "Square.hpp"

Square::Square(PieceType pieceType)
    : pieceType_(pieceType) {}

PieceType Square::getPieceType() {
    return pieceType_;
}