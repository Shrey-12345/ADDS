#include "Referee.h"

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    // Tie condition
    if (move1->getName() == move2->getName()) {
        delete move1;
        delete move2;
        return nullptr;
    }

    Player* winner = nullptr;

    if (move1->beats(*move2)) {
        winner = player1;
    } else if (move2->beats(*move1)) {
        winner = player2;
    } else {
        winner = nullptr; // In case neither beats the other, treat as tie
    }

    delete move1;
    delete move2;

    return winner;
}