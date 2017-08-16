#ifndef DATASTRUCTURES_MYLINKEDLIST_H
#define DATASTRUCTURES_MYLINKEDLIST_H

struct Node {
    int data;
    Node *next;
};

class MyLinkedList {
private:
    Node* root;

public:
    MyLinkedList();
    void insertNode(int data);
    void removeNode();
    void reverseLinkedList();
    ~MyLinkedList();

};


#endif //DATASTRUCTURES_MYLINKEDLIST_H
