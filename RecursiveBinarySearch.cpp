#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(std::vector<int> list, int target) {
    if (list.empty()) return false;
    return binarySearch(list, target, 0, list.size() - 1);
}

bool RecursiveBinarySearch::binarySearch(const std::vector<int>& list, int target, int low, int high) {
    if (low > high) return false;

    int mid = low + (high - low) / 2;
    if (list[mid] == target) return true;
    else if (target < list[mid]) {
        return binarySearch(list, target, low, mid - 1);
    } else {
        return binarySearch(list, target, mid + 1, high);
    }
}
