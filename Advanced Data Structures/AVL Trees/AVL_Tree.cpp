//
// Created by Shehab Abdel-Salam on 7/27/18.
//

#include "AVL_Tree.h"

AVL_Tree::AVL_Tree() : root(nullptr) {}

TreeNode *AVL_Tree::NewTreeNode(int k) {
    TreeNode *t = new TreeNode;
    t->key = k;
    t->left = nullptr;
    t->right = nullptr;
    t->height = 1;
    return t;
}

TreeNode *AVL_Tree::Right_Rotate(TreeNode *y) {
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

TreeNode *AVL_Tree::Left_Rotate(TreeNode *x) {
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    // Perform Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int AVL_Tree::getBalance(TreeNode *t) {
    if (t == nullptr) return 0;
    return height(t->left) - height(t->right);
}

int AVL_Tree::height(TreeNode *n) {
    if (n == nullptr)
        return 0;
    return n->height;
}

int AVL_Tree::max(int a, int b) { return (a > b) ? a : b; }

TreeNode *AVL_Tree::_Insert(TreeNode *root, int key) {
    // Normal BST INSERTION
    if (root == NULL)
        return NewTreeNode(key);

    if (key < root->key)
        root->left = _Insert(root->left, key);
    else if (key > root->key)
        root->right = _Insert(root->right, key);
    else    // no equal keys in BST.
        return root;

    // Update height of this ancestor node.
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance factor of this ancestor node to check whether this node became unbalanced.
    int balance = getBalance(root);

    // If no balance, then there are 4 cases.

    // LL Case
    if (balance > 1 && key < root->left->key)
        return Right_Rotate(root);

    // RR Case
    if (balance < -1 && key > root->right->key)
        return Left_Rotate(root);

    // LR Case
    if (balance > 1 && key > root->left->key) {
        root->left = Left_Rotate(root->left);
        return Right_Rotate(root);
    }

    // RL Case
    if (balance < -1 && key < root->right->key) {
        root->right = Right_Rotate(root->right);
        return Left_Rotate(root);
    }

    return root;
}

void AVL_Tree::_PreOrder(TreeNode *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        _PreOrder(root->left);
        _PreOrder(root->right);
    }
}

AVL_Tree::~AVL_Tree() {};
