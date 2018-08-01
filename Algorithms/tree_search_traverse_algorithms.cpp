#include <iostream>
#include <queue>

struct treeNode {
    int value;
    treeNode *left = new treeNode;
    treeNode *right = new treeNode;
};

// Root - Left Child - Right Child.
void PreOrderTraversal(treeNode *root) {
    if (root == nullptr)
        return;
    std::cout << root->value << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

// Left Child - Root - Right Child.
void InOrderTraversal(treeNode *root) {
    if (root == nullptr)
        return;
    InOrderTraversal(root->left);
    std::cout << root->value << " ";
    InOrderTraversal(root->right);
}

// Left Child - Right Child - Root.
void PostOrderTraversal(treeNode *root) {
    if (root == nullptr)
        return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    std::cout << root->value << " ";
}

// Breath First Search for BST.
treeNode *BFS(treeNode *root, int value) {
    std::queue<treeNode *> Q;
    if (root == nullptr)
        return nullptr;
    Q.push(root);
    while (!Q.empty()) {
        treeNode *temp = Q.front();
        Q.pop();
        if (temp->value == value)
            return temp;
        if (temp->left != nullptr)
            Q.push(temp->left);
        if (temp->right != nullptr)
            Q.push(temp->right);
    }
}

// Depth First Search for BST
treeNode *DFS(treeNode *root, int value) {
    if (root->value == value)
        return root;
    DFS(root->left, value);
    DFS(root->right, value);
}