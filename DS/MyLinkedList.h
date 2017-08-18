#ifndef DATASTRUCTURES_MYLINKEDLIST_H
#define DATASTRUCTURES_MYLINKEDLIST_H

class MyLinkedList {
private:

    struct listNode {
        int data;
        listNode *next;
    };

    listNode *root;

public:
    MyLinkedList();
    void insertNode(int data);
    void removeNode();
    void reverseLinkedList();
    ~MyLinkedList();

};


#endif //DATASTRUCTURES_MYLINKEDLIST_H
