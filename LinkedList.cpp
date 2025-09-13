#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    if (len <= 0) return;
    head = new Node(array[0]);
    Node* current = head;
    for (int i = 1; i < len; i++) {
        current->setLink(new Node(array[i]));
        current = current->getLink();
    }
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->getLink();
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);

    if (pos <= 1 || head == nullptr) {
        newNode->setLink(head);
        head = newNode;
        return;
    }

    Node* current = head;
    int index = 1;

    while (current->getLink() != nullptr && index < pos - 1) {
        current = current->getLink();
        index++;
    }

    newNode->setLink(current->getLink());
    current->setLink(newNode);
}

bool LinkedList::deletePosition(int pos) {
    if (head == nullptr || pos < 1) return false;

    if (pos == 1) {
        Node* temp = head;
        head = head->getLink();
        delete temp;
        return true;
    }

    Node* current = head;
    int index = 1;

    while (current->getLink() != nullptr && index < pos - 1) {
        current = current->getLink();
        index++;
    }

    if (current->getLink() == nullptr) return false;

    Node* temp = current->getLink();
    current->setLink(temp->getLink());
    delete temp;
    return true;
}

int LinkedList::get(int pos) {
    if (pos < 1) return std::numeric_limits<int>::max();

    Node* current = head;
    int index = 1;

    while (current != nullptr && index < pos) {
        current = current->getLink();
        index++;
    }

    if (current == nullptr) return std::numeric_limits<int>::max();
    return current->getData();
}

int LinkedList::search(int target) {
    Node* current = head;
    int index = 1;

    while (current != nullptr) {
        if (current->getData() == target) return index;
        current = current->getLink();
        index++;
    }
    return -1;
}

void LinkedList::printList() const {
    if (head == nullptr) return;

    std::cout << "[";
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->getData();
        if (current->getLink() != nullptr) std::cout << " ";
        current = current->getLink();
    }
    std::cout << "]";
}
