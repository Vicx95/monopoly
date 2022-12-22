#pragma once

#include <vector>
#include <memory>

class Guest;

class Square {
public:
    virtual void onPass(Guest& player) const = 0;
    virtual void onLand(Guest& player) const = 0;
};

class StartSquare : public Square {
public:
    void onPass(Guest& player) const override;
    void onLand(Guest& player) const override;
};

class PenaltySquare : public Square {
public:
    void onPass(Guest& player) const override;
    void onLand(Guest& player) const override;
};

class RewardSquare : public Square {
public:
    void onPass(Guest& player) const override;
    void onLand(Guest& player) const override;
};

class PrisonSquare : public Square{
public:
    void onPass(Guest& player) const override;
    void onLand(Guest& player) const override;
};

class RandomSquare : public Square{
public:
    RandomSquare(){
        randomSquares_.push_back(std::make_unique<RewardSquare>());
        randomSquares_.push_back(std::make_unique<PenaltySquare>());
        randomSquares_.push_back(std::make_unique<PrisonSquare>());
    }
    void onPass(Guest& player) const override;
    void onLand(Guest& player) const override;  
private:

    std::vector<std::unique_ptr<Square>> randomSquares_;
};