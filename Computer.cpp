#include "Computer.h"
#include "Move.h"
#include <cstdlib>
#include <ctime>
#include <vector>

static bool seeded = false;

Computer::Computer() : name("Computer") {
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        seeded = true;
    }
}

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