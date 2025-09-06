#include "QuickSort.h"
#include <algorithm> // for std::swap

std::vector<int> QuickSort::sort(std::vector<int> list) {
    if (!list.empty()) {
        quickSort(list, 0, list.size() - 1);
    }
    return list;
}

void QuickSort::quickSort(std::vector<int>& list, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(list, low, high);
        quickSort(list, low, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, high);
    }
}

int QuickSort::partition(std::vector<int>& list, int low, int high) {
    int pivotIndex;
    if (high - low + 1 >= 3) {
        pivotIndex = low + 2; // the third element in the sublist
    } else {
        pivotIndex = low; // fallback for <3 elements
    }

    int pivotValue = list[pivotIndex];
    std::swap(list[pivotIndex], list[high]);

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (list[j] <= pivotValue) {
            i++;
            std::swap(list[i], list[j]);
        }
    }
    std::swap(list[i + 1], list[high]);
    return i + 1;
}
