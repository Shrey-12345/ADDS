#include "Referee.h"

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    Player* winner = nullptr;

    if (move1->getName() == move2->getName()) {
        // Tie condition
        winner = nullptr;
    } else if (move1->beats(*move2)) {
        winner = player1;
    } else if (move2->beats(*move1)) {
        winner = player2;
    } else {
        winner = nullptr;
    }

    delete move1;
    delete move2;

    return winner;
}