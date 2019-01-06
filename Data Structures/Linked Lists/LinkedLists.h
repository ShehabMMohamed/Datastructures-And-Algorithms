#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

class LinkedList {
private:

    struct listNode {
        int data;
        listNode *next;
    };

    listNode *root;

    listNode *createNode(int data);

    void deleteNode(const int pos);

public:
    LinkedList();

    void insert_node_front(int data);

    void insert_node_specific_pos(int data);

    void remove_specific_node(const int pos);

    void reverse_list();

    ~LinkedList();

};


#endif 
