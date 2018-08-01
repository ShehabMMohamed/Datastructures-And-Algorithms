//
// Created by Shehab Abdel-Salam on 7/27/18.
//

#ifndef DATASTRUCTURES_AVL_TREE_H
#define DATASTRUCTURES_AVL_TREE_H

#include <stdio.h>

class TreeNode {
public:
    int key;
    int height;
    TreeNode *left;
    TreeNode *right;
};

class AVL_Tree {

private:

    TreeNode *root;

    int height(struct TreeNode *t);

    int max(int, int);

    TreeNode *NewTreeNode(int k);

    TreeNode *Right_Rotate(TreeNode *t);

    TreeNode *Left_Rotate(TreeNode *t);

    int getBalance(TreeNode *t);

    TreeNode *_Insert(TreeNode *root, int key);

    TreeNode *_Delete(TreeNode *root, int key);

    void _PreOrder(TreeNode *root);

public:
    AVL_Tree();

    void Insert(int key) { root = _Insert(root, key); }

    void Delete(int key) { root = _Delete(root, key); }

    void Search(int key);

    void PreOrder() { _PreOrder(root); };

    ~AVL_Tree();

};


#endif //DATASTRUCTURES_AVL_TREE_H
