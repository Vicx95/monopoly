#pragma once
#include <cstdio>

class Dice {
public:
    Dice();
    Dice(std::size_t numOfSides);
    Dice(std::size_t numOfDice, std::size_t numOfSides);

    unsigned int getRolledValue() const;

private:
    std::size_t numOfDice_;
    std::size_t numOfSides_;
};