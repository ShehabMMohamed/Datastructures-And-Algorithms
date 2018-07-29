#ifndef DATASTRUCTURES_BST_H
#define DATASTRUCTURES_BST_H

class MyBST {
private:
    struct BST_Node {
        int data;
        BST_Node *right;
        BST_Node *left;
    };

    BST_Node* root;
public:
    MyBST();

    void InsertNode(int);

    void RemoveNode(BST_Node *);
    ~MyBST();

};


#endif //DATASTRUCTURES_BST_H
