//
// Created by Shehab Mohamed on 8/6/17.
//

#ifndef DATASTRUCTURES_BST_H
#define DATASTRUCTURES_BST_H

struct BST_Node {
    int data;
    BST_Node* right;
    BST_Node* left;
};

class MyBST {
private:
    BST_Node* root;
public:
    MyBST();
    void InsertNode(int data);
    void RemoveNode(int data);
    ~MyBST();

};


#endif //DATASTRUCTURES_BST_H
