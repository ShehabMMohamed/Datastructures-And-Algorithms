#include "RedBlackTrees.h"


RedBlackTrees::RedBlackTrees() : root(nullptr) {};

void RedBlackTrees::RotateLeft(TreeNode *x) {
    TreeNode* y = x->right;
    x->right = y->left;

    if(y->left != nullptr)
        y->left->parent = x;

    y->parent = x->parent;

    if(x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)      // left child of the parent.
        x->parent->left = y;
    else
        x->parent->right = y;           // right child of the parent.

    y->left = x;
    x->parent = y;
}