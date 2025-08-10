#include "Human.h"
#include "Move.h"
#include <iostream>
#include <memory>  // for std::unique_ptr

Human::Human(const std::string& name) : name(name) {}

Move* Human::makeMove() {
    std::string input;
    while (true) {
        std::cout << "Enter move (Rock, Paper, Scissors, Robot, Monkey, Pirate, Ninja, Zombie): ";
        std::getline(std::cin, input);

        // Normalize input - remove leading/trailing whitespace (optional)
        // Could add lowercase conversion here if needed

        if (Move::isValidMove(input)) {
            return new Move(input);
        } else {
            std::cout << "Invalid move. Please try again.\n";
        }
    }
}

std::string Human::getName() {
    return name;
}