#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

template <typename T>
class ListNode {
public:
    T data;
    ListNode* next;
    ListNode(const T& item) : data (item), next (NULL) {};
};

template <typename T>
class LinkedList {
private:
    ListNode<T> *root;
    ListNode *createNode(int data);
    void deleteNode(const int pos);

public:
    LinkedList() {};
    ~LinkedList() {};
};


#endif 
