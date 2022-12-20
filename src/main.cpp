
#include <vector>
#include "MonopolyGame.hpp"
#include "Player.hpp"
int main() {
    Board board;
    std::vector<Player> playersVector = {
        {"Adam", board},
        {"Patryk", board}};
    MonopolyGame monopoly(playersVector, board);
}