#pragma once

class Player;

class Square {
public:
    virtual void onPass(Player& player) const = 0;
    virtual void onLand(Player& player) const = 0;
};

class StartSquare : public Square {
public:
    void onPass(Player& player) const override;
    void onLand(Player& player) const override;
};

class PenaltySquare : public Square {
public:
    void onPass(Player& player) const override;
    void onLand(Player& player) const override;
};

class RewardSquare : public Square {
public:
    void onPass(Player& player) const override;
    void onLand(Player& player) const override;
};