#include <iostream>
#include <sstream>
#include <vector>

#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);

    std::vector<int> numbers;
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }

    // Sort using QuickSort
    QuickSort sorter;
    numbers = sorter.sort(numbers);

    // Search for 1 using RecursiveBinarySearch
    RecursiveBinarySearch searcher;
    bool found = searcher.search(numbers, 1);

    std::cout << (found ? "true" : "false");
    for (int x : numbers) {
        std::cout << " " << x;
    }
    std::cout << std::endl;

    return 0;
}
