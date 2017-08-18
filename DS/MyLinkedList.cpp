#include "MyLinkedList.h"

MyLinkedList::MyLinkedList() {
    this->root = nullptr;
}

void MyLinkedList::insertNode(int data) {
    listNode *newNode = new listNode;
    newNode->data = data;
    if(root == nullptr)
        root = newNode;
    else {
        listNode *temp = root->next;
        while (true)
        {
            if(temp->next == nullptr)
            {
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