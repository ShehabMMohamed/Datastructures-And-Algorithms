//
// Created by Shehab Abdel-Salam on 7/27/18.
//

#ifndef DATASTRUCTURES_AVL_TREE_H
#define DATASTRUCTURES_AVL_TREE_H

#include <stdio.h>

class AVL_Tree {

private:
    struct Node {
        int key;
        Node *left;
        Node *right;
        int height;
    };
    Node *root;

    int height(Node *t);

    int max(int, int);

    Node *NewNode(int key);

    Node *Right_Rotate(Node *t);

    Node *Left_Rotate(Node *t);

    int getBalance(Node *t);

    Node *_Insert(Node *root, int key);

    Node *_Delete(Node *root, int key);


public:
    AVL_Tree() { root = NULL; }

    void Insert(int key) { root = _Insert(root, key); }

    void Delete(int key) { root = _Delete(root, key); }

    void Search(int key);

    ~AVL_Tree();


};


#endif //DATASTRUCTURES_AVL_TREE_H
