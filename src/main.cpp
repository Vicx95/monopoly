
#include "MonopolyGame.hpp"
int main() {
    const std::size_t numOfDice = 3;
    const std::size_t numOfSides = 6;
    Dice dice(numOfDice, numOfSides);

    const std::size_t boardSize = 10;
    Board board(boardSize);
    MonopolyGame monopoly(board, dice);

    monopoly.addPlayer("Adam");
    monopoly.addPlayer("Patryk");

    const int numOfRounds = 2;
    monopoly.startGame(numOfRounds);
}