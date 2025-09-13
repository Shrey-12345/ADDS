#include "Node.h"

Node::Node(int value, Node* next) : data(value), link(next) {}

Node::~Node() {}

int Node::getData() const {
    return data;
}

void Node::setData(int value) {
    data = value;
}

Node* Node::getLink() const {
    return link;
}

void Node::setLink(Node* next) {
    link = next;
}
