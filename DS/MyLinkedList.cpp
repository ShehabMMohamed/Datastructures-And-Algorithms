#include "MyLinkedList.h"

MyLinkedList::MyLinkedList() : root(nullptr) {}

listNode *MyLinkedList::createNode(int data) {
    listNode *newNode = new listNode;
    newNode->data = data;
    return listNode;
}

void MyLinkedList::insertNode(int d) {
    listNode *newNode = MyLinkedList::createNode(d);
    if(root == nullptr)
        root = newNode;
    else {
        listNode *temp = root->next;
        while (true) {
            if(temp->next == nullptr) {
                temp->next = newNode;
                root = temp;
                break;
            }
            temp = temp->next;
        }
    }
}

void MyLinkedList::removeNode() {
    if(root->next == nullptr)
        delete root;
    else
    {
        listNode *temp = root;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp;
    }
}