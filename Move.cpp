#include "Move.h"
#include <algorithm>
#include <cctype>

// List of moves with exact casing as expected
static const std::vector<std::string> allMoves = {
    "Rock", "Paper", "Scissors", "Robot", "Monkey", "Pirate", "Ninja", "Zombie"
};

static const std::vector<std::pair<std::string, std::vector<std::string>>> beatsMap = {
    {"Rock",     {"Scissors", "Monkey"}},
    {"Paper",    {"Rock", "Robot"}},
    {"Scissors", {"Paper", "Monkey"}},
    {"Robot",    {"Ninja", "Zombie"}},
    {"Monkey",   {"Ninja", "Robot"}},
    {"Pirate",   {"Robot", "Monkey"}},
    {"Ninja",    {"Pirate", "Zombie"}},
    {"Zombie",   {"Pirate", "Monkey"}},
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
            if (std::find(entry.second.begin(), entry.second.end(), other.name) != entry.second.end()) {
                return true;
            }
            break;
        }
    }
    return false;
}