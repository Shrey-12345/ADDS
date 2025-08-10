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

    bool beats(const Move& other) const;

    static bool isValidMove(const std::string& moveName);
};

#endif