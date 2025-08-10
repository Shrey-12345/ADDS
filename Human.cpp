#include "Human.h"
#include "Move.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

Human::Human(const std::string& name) : name(name) {}

Move* Human::makeMove() {
    std::string input;
    while (true) {
        std::cout << "Enter move (Rock, Paper, Scissors, Robot, Monkey, Pirate, Ninja, Zombie): ";
        std::getline(std::cin, input);

        // Trim leading and trailing spaces
        input.erase(input.begin(), std::find_if(input.begin(), input.end(), [](unsigned char ch) { return !std::isspace(ch); }));
        input.erase(std::find_if(input.rbegin(), input.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), input.end());

        // **Do not change case to lowercase** because moves are case sensitive in validation.

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