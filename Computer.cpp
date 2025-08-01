#include "Computer.h"

Computer::Computer() : name("Computer") {}

char Computer::makeMove() {
    return 'R';
}

std::string Computer::getName() {
    return name;
}
