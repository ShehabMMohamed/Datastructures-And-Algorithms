//
// Created by Shehab Abdel-Salam on 7/27/18.
//

#include "AVL_Tree.h"

AVL_Tree::AVL_Tree(int k) {
    root->key = k;
    root->height = 1;
}

Node *AVL_Tree::NewNode(int k) {
    Node *node = new Node;
    node->key = k;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

AVL_Tree::Node *AVL_Tree::Right_Rotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVL_Tree::Node *AVL_Tree::Left_Rotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int AVL_Tree::getBalance(Node *t) {
    if (t == NULL) return 0;
    return height(t->left) - height(t->right);
}

int AVL_Tree::height(Node *n) {
    if (n == nullptr)
        return 0;
    return n->height;
}

int AVL_Tree::max(int a, int b) { return (a > b) ? a : b; }

Node *AVL_Tree::Insert(Node *node, int k) {
    // Normal BST INSERTION
    if (node == NULL)
        return NewNode(k);

    if (k < node->key)
        node->left = Insert(node->left, k);
    else if (k > node->key)
        node->right = Insert(node->right, k);
    else    // no equal keys in BST.
        return node;

    // Update height of this ancestor node.
    node->height = 1 + max(height(node->left), height(node->right));

    // Get balance factor of this ancestor node to check whether this node became unbalanced.
    int balance = getBalance(node);

    // If no balance, then there are 4 cases.

    // LL Case
    if (balance > 1 && k < node->left->key)
        return Right_Rotate(node);

    // RR Case
    if (balance < -1 && k > node->right->key)
        return Left_Rotate(node);

    // LR Case
    if (balance > 1 && k > node->left->key) {
        node->left = Left_Rotate(node->left);
        return Right_Rotate(node);
    }

    // RL Case
    if (balance < -1 && k < node->right->key) {
        node->right = Right_Rotate(node->right);
        return Left_Rotate(node);
    }

    return node;
}

AVL_Tree::~AVL_Tree() {};
