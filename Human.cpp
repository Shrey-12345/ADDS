#include "Human.h"
#include <iostream>
#include <string>
using namespace std;

Human::Human(string n) {
    name = n;
}

char Human::makeMove() {
    char move;
    cout << "Enter move: ";
    cin >> move;
    return move;
}

string Human::getName() {
    return name;
}