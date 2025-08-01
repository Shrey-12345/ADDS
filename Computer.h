#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include "Player.h"

class Computer : public Player {
private:
    std::string name;

public:
    Computer();
    char makeMove() override;
    std::string getName() override;
};

#endif
