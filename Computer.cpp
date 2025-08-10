#include "Computer.h"
#include "Move.h"
#include <cstdlib>
#include <vector>

Computer::Computer() : name("Computer") {}

Move* Computer::makeMove() {
    static const std::vector<std::string> moves = {
        "Rock", "Paper", "Scissors", "Robot", "Monkey", "Pirate", "Ninja", "Zombie"
    };
    int index = std::rand() % moves.size();
    return new Move(moves[index]);
}

std::string Computer::getName() {
    return name;
}