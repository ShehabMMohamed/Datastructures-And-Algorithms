//
// Created by Shehab Mohamed on 8/6/17.
//

#include "MyLinkedList.h"

MyLinkedList::MyLinkedList() {
    this->root = nullptr;
}

void MyLinkedList::insertNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    if(root == nullptr)
        root = newNode;
    else {
        Node* temp = root->next;
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
        Node* temp = root;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp;
    }
}