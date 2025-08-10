#include "Computer.h"
#include "Move.h"
#include <vector>

Computer::Computer() : name("Computer") {}

Move* Computer::makeMove() {
    
    static const std::vector<std::string> moves = {
        "Rock", "Rock", "Rock", "Rock", "Rock", "Rock", "Rock", "Rock"
    };
    static int index = 0;
    Move* move = new Move(moves[index % moves.size()]);
    index++;
    return move;
}

std::string Computer::getName() {
    return name;
}