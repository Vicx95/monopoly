
#include "MonopolyGame.hpp"
int main() {
    const std::size_t numOfDice = 1;
    const std::size_t numOfSides = 6;
    Dice dice(numOfDice, numOfSides);

    //const std::size_t boardSize = 10;
    // Board board(boardSize);
    Board board;
    MonopolyGame monopoly(board, dice);

    monopoly.addPlayer("Adam");
    monopoly.addPlayer("Patryk");

    const int numOfRounds = 20;
    monopoly.startGame(numOfRounds);
}