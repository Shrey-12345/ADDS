#include <iostream>
#include <cstdlib>  // For srand()
#include <ctime>    // For time()
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    // Seed random once globally
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create players and referee
    Human human("Human");
    Computer computer;
    Referee referee;

    // Play a single game
    Player* winner = referee.refGame(&human, &computer);

    // Print results
    if (winner == nullptr) {
        std::cout << "Tie\n";
    } else {
        std::cout << winner->getName() << std::endl;
    }

    return 0;
}