#pragma once

enum class PieceType {
    Start,
    Penalty,
    Reward
};

class Square {
public:
    Square() = default;
    explicit Square(PieceType pieceType);
    PieceType getPieceType();

private:
    PieceType pieceType_;
};