#include "Move.h"
#include <algorithm>

// List of moves
static const std::vector<std::string> allMoves = {
    "Rock", "Paper", "Scissors", "Robot", "Monkey", "Pirate", "Ninja", "Zombie"
};

// This map defines which moves each move beats
static const std::vector<std::pair<std::string, std::vector<std::string>>> beatsMap = {
    {"Rock",     {"Scissors", "Monkey"}},         // Rock beats Scissors and Monkey
    {"Paper",    {"Rock", "Robot"}},              // Paper beats Rock and Robot
    {"Scissors", {"Paper", "Monkey"}},            // Scissors beats Paper and Monkey
    {"Robot",    {"Ninja", "Zombie"}},            // Robot beats Ninja and Zombie
    {"Monkey",   {"Ninja", "Robot"}},             // Monkey beats Ninja and Robot
    {"Pirate",   {"Robot", "Monkey"}},            // Pirate beats Robot and Monkey
    {"Ninja",    {"Pirate", "Zombie"}},           // Ninja beats Pirate and Zombie
    {"Zombie",   {"Pirate", "Monkey"}},           // Zombie beats Pirate and Monkey
};

Move::Move(const std::string& name) : name(name) {}

std::string Move::getName() const {
    return name;
}

bool Move::isValidMove(const std::string& moveName) {
    return std::find(allMoves.begin(), allMoves.end(), moveName) != allMoves.end();
}

bool Move::beats(const Move& other) const {
    for (const auto& entry : beatsMap) {
        if (entry.first == name) {
            // Check if other.name is in this move's beat list
            if (std::find(entry.second.begin(), entry.second.end(), other.name) != entry.second.end()) {
                return true;
            }
            break;
        }
    }
    return false;
}