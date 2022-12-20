#include "Player.hpp"
#include <iostream>
#include <random>

Player::Player(std::string name, const Board& board)
    : playerName_(name), board_(board) {}

void Player::move() {
    [[maybe_unused]] auto result = throwDices() + position_;
    if (result > board_.getBoardSize() - 1) {
        std::cout << "Player " << playerName_ <<"moved through the start\n"
                  << "Player gets 400 zl reward";
        money_ += 400;
        position_ = result - board_.getBoardSize() - 1;
        return;
    }
    auto squareInfo = board_.getSquareInfo(position_);
    checkSquare(squareInfo);

}

std::string Player::getName() const {
    return playerName_;
}

int Player::getPosition() const {
    return position_;
}

int Player::getMoney() const {
    return money_;
}

int Player::throwDices() {
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> dice{2, 12};
    return dice(gen);
}

void Player::checkSquare(const Square& square) {
    if (square.getPieceType() == PieceType::Penalty) {
        std::cout << "Player " << playerName_ << " stayed at Penalty Piece\n"
                  << "Player have to pay 400 zl penalty\n";
        money_ -= 400;
    }
    else if(square.getPieceType() == PieceType::Reward){
        std::cout << "Player " << playerName_ << " stayed at Reward Piece\n"
                  << "Player have to get 400 zl reward\n";
        money_ += 400;
    }else{
        std::cout << "Player " << playerName_ << " stayed at Neutral Piece";
    } 
}