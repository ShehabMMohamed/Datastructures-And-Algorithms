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

class BST {
private:
    BST_Node* root;
public:
    BST();
    void InsertNode(int data);
    void RemoveNode(int data);
    ~BST();

};


#endif //DATASTRUCTURES_BST_H
