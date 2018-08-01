#include "BinarySearchTrees.h"

TreeNode *BST::_Insert(TreeNode *root, int key) {
    if (root == nullptr)
        return TreeNode(key);

    if (key > root->key)
        return _Insert(root->right, key);

    else if (key < root->key)
        return _Insert(root->left, key);

    else    // No duplicates.
        return root;
}

TreeNode *BST::_Delete(TreeNode *root, int key) {
    if (root == nullptr) {
        printf("Node with key %d doesn't exist in the tree.", key);
        return root;
    }

    if (root->key == key) {
        // Three cases.
    }
}