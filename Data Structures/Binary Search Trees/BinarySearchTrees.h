#ifndef BINARYSEARCHTREES_H
#define BINARYSEARCHTREES_H
#include <stdio.h>
#include <iostream>
class TreeNode {
public:
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int k) : key(k), left(NULL), right(NULL) {};
};

class BST {
private:

    TreeNode *root;
    TreeNode *_Insert(TreeNode *root, int key);
    TreeNode *_Delete(TreeNode *root, int key);
    TreeNode *_GetSmallest(TreeNode *root);
    TreeNode *_GetLargest(TreeNode *root);
    void _Search(TreeNode *root, int key);

public:
    BST() : root(nullptr) {};
    void InsertNode(int k) { root = _Insert(root, k); }
    void DeleteNode(int k) { root = _Delete(root, k); }
    void SearchNode(int k) { root = _Search(root, k); }
    void GetSmallestNode() { root = _GetSmallest(root); }
    void GetLargestNode() { root = _GetLargest(root); }
    void PreOrder();
    void InOrder();
    void PostOrder();
    ~BST() {};
};

#endif 
