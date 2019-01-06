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

TreeNode *BST::_GetSmallest(TreeNode *root) {
    if (root->left == nullptr) return root;
    root = _GetSmallest(root->left);
}

TreeNode *BST::_GetLargest(TreeNode *root) {
    if (root->right == nullptr) return root;
    root = _GetLargest(root->right);
}

TreeNode *BST::_Delete(TreeNode *root, int key) {
    if (root == nullptr) {
        printf("Node with key %d doesn't exist in the tree.", key);
        return root;
    }

    if (key < root->key)
        root = _Delete(root->left, key);

    else if (key > root->key)
        root = _Delete(root->right, key);

    else {   // (root->key == key)
        // Three cases.
        // one child.
        if (root->left == nullptr) {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        } else {
            // two children.
            // Find In-Order Successor.
            TreeNode *temp = _GetSmallest(root->right);
            root->key = temp->key;

            root->right = _Delete(root->right, root->key);

            // OR ...
            // Find In-Order Predecessor.
            //TreeNode *temp = _GetLargest(root->left);
            //root->key = temp->key;

            //root->left = _Delete(root->left, root->key);

        }
    }
    return root;
}

void BST::_Search(TreeNode *root, int key) {
    if (root == nullptr) {
        printf("Node not found.\n");
        return;
    }
    if (root->key == key) {
        printf("Found Node with key = %d.\n", key);
        return;
    }
    if (root->key < key)
        _Search(root->right, key);
    if (root->key > key)
        _Search(root->left, key);
}