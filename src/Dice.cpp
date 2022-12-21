#include "Dice.hpp"
#include <random>

Dice::Dice()
    : numOfDice_(1), numOfSides_(6) {
}

Dice::Dice(std::size_t numOfSides)
    : numOfDice_(1),
      numOfSides_(numOfSides) {
}

Dice::Dice(std::size_t numOfDice, std::size_t numOfSides)
    : numOfDice_(numOfDice),
      numOfSides_(numOfSides) {
}

unsigned int Dice::getRolledValue() const {
    unsigned int result = 0;
    for (unsigned int i = 0; i < numOfDice_; ++i) {
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::uniform_int_distribution<> dice{1, static_cast<int>(numOfSides_)};
        result += dice(gen);
    }
    return result;
}
