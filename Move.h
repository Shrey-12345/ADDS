#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <vector>

class Move {
private:
    std::string name;

public:
    Move(const std::string& name);
    std::string getName() const;

    // Returns true if this move beats the other move
    bool beats(const Move& other) const;

    // Static helper to validate and create a Move from a string
    static bool isValidMove(const std::string& moveName);
};

#endif