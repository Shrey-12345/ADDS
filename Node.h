#ifndef NODE_H
#define NODE_H

class Node {
private:
    int data;
    Node* link;

public:
    Node(int value, Node* next = nullptr);
    ~Node();

    int getData() const;
    void setData(int value);

    Node* getLink() const;
    void setLink(Node* next);
};

#endif
