#include <vector>
#include <queue>
using namespace std;

int kth_largest(vector<int> values, int k) {
    // Use a min-heap of size k
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int val : values) {
        minHeap.push(val);

        // Keep only the k largest elements in the heap
        if ((int)minHeap.size() > k)
            minHeap.pop();
    }

    // The top element is the k-th largest
    return minHeap.top();
}
