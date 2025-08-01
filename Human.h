// Human.h
#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"

class Human : public Player {
private:
    string name;
public:
    Human();
    Human(string n = "Human");
    char makeMove() override;
    string getName() override;
};

#endif