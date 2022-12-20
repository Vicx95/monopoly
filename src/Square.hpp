#pragma once

enum class PieceType {
    Start,
    Penalty,
    Reward
};

class Square {
public:
    PieceType getPieceType();

private:
    PieceType pieceType_;
};