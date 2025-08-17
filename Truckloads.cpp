#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize) {
    if (numCrates <= 0 || loadSize <= 0) {
        return 0; // error case
    }

    if (numCrates <= loadSize) {
        return 1; // one truck is enough
    }

    // split crates into two piles
    int leftPile = numCrates / 2;
    int rightPile = numCrates - leftPile;

    return numTrucks(leftPile, loadSize) + numTrucks(rightPile, loadSize);
}