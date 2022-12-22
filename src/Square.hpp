#pragma once

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