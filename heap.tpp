#include <stdexcept>

// Insert a new element into the heap
template <typename T>
void Heap<T>::insert(const T& value) {
    // Add the new value at the end
    elements.push_back(value);
    // Restore the heap property by moving the new element up
    heapifyUp(elements.size() - 1);
}

// Remove the minimum element (root) from the heap
template <typename T>
void Heap<T>::remove() {
    if (elements.empty())
        throw std::underflow_error("Heap is empty");

    // Move last element to root and remove last
    elements[0] = elements.back();
    elements.pop_back();

    // Restore heap property by moving down
    if (!elements.empty())
        heapifyDown(0);
}

// Get the minimum (root) element
template <typename T>
T Heap<T>::getMin() const {
    if (elements.empty())
        throw std::underflow_error("Heap is empty");
    return elements[0];
}

// Helper: move element at index up to restore heap
template <typename T>
void Heap<T>::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (elements[index] < elements[parent]) {
            std::swap(elements[index], elements[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

// Helper: move element at index down to restore heap
template <typename T>
void Heap<T>::heapifyDown(int index) {
    int size = elements.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && elements[left] < elements[smallest])
            smallest = left;
        if (right < size && elements[right] < elements[smallest])
            smallest = right;

        if (smallest != index) {
            std::swap(elements[index], elements[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}
