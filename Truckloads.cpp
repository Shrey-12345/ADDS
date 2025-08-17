#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize) {
    if (numCrates <= 0 || loadSize <= 0) {
        return 0;
    }

    if (numCrates <= loadSize) {
        return 1;
    }

    int leftPile = numCrates / 2;
    int rightPile = numCrates - leftPile;

    return numTrucks(leftPile, loadSize) + numTrucks(rightPile, loadSize);
}