//
// Created by Shehab Abdel-Salam on 7/29/18.
//

#ifndef DATASTRUCTURES_REDBLACKTREES_H
#define DATASTRUCTURES_REDBLACKTREES_H

#include "stdio.h"

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

    void RotateRight(TreeNode *T, TreeNode *y);

    void RotateLeft(TreeNode *T, TreeNode *x);

    bool _insert(TreeNode *T, int key);

    bool _delete(TreeNode *T, int key);

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
