#ifndef DATASTRUCTURES_REDBLACKTREES_H
#define DATASTRUCTURES_REDBLACKTREES_H

#include "stdio.h"
#include "iostream"

class TreeNode {
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    int key;
    bool color;     // False -> Black, True -> Red

    TreeNode(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class RedBlackTrees {

private:
    TreeNode *root;

    void RotateRight(TreeNode *y);

    void RotateLeft(TreeNode *x);

    bool _insert(TreeNode *root, int key);

    bool _delete(TreeNode *root, int key);

    int black_height(TreeNode *X);

public:
    RedBlackTrees();

    void Insert(int key) {
        if (_insert(root, key))
            printf("Success - Inserted key %d to the tree.\n" % key);
        else
            printf("Error - Didn't insert key %d to the tree.\n" % key);
    }

    void Delete(int key) {
        if (_delete(root, key))
            printf("Success - Delete key %d from the tree.\n" % key);
        else
            printf("Error - Didn't delete key %d from the tree.\n" % key);
    }

    ~RedBlackTrees();

};


#endif //DATASTRUCTURES_REDBLACKTREES_H
