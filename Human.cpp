#include "Human.h"
#include "Move.h"
#include <iostream>
#include <string>

Human::Human(const std::string& name) : name(name) {}

Move* Human::makeMove() {
    std::string input;
    std::getline(std::cin, input);
    return new Move(input);
}

std::string Human::getName() {
    return name;
}