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
    PieceType getPieceType() const;

private:
    PieceType pieceType_;
};