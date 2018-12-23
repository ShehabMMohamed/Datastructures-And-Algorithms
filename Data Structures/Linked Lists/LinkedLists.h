#ifndef DATASTRUCTURES_MYLINKEDLIST_H
#define DATASTRUCTURES_MYLINKEDLIST_H

class MyLinkedList {
private:

    struct listNode {
        int data;
        listNode *next;
    };

    listNode *root;

    listNode *createNode(int data);

    void deleteNode(const int pos);

public:
    MyLinkedList();

    void insert_node_front(int data);

    void insert_node_specific_pos(int data);

    void remove_specific_node(const int pos);

    void reverse_list();

    ~MyLinkedList();

};


#endif //DATASTRUCTURES_MYLINKEDLIST_H
