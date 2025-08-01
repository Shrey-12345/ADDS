#include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    Human h("Mei");
    Computer c;
    Referee r;

    Player* winner = r.refGame(&h, &c);
    if (winner == nullptr) {
        cout << "It's a Tie." << endl;
    } else {
        cout << winner->getName() << " Wins." << endl;
    }

    return 0;
}