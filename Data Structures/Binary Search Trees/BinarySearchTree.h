#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <stdio.h>
#include <iostream>
#include <exception>

class TreeNode {
public:
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode(const int& k) : key(k), left(nullptr), right(nullptr) {};
};

class BinarySearchTree {
private:
    TreeNode *root;
    bool _search(TreeNode *node, const int& key);
    TreeNode* _insert(TreeNode *node, const int& key);
    TreeNode* _delete(TreeNode *node, const int& key);
    TreeNode* _minimum(TreeNode *node);
    TreeNode* _maximum(TreeNode *node);
    void _pre_order(TreeNode* node);
    void _in_order(TreeNode* node);
    void _post_order(TreeNode* node);
    void _destroy_recusrive(TreeNode* node);

public:
    BinarySearchTree();
    void Add(const int& key);
    void Delete(const int& key);
    void Search(const int& key);
    int Minimum();
    int Maximum();
    void PreOrder();
    void InOrder();
    void PostOrder();
    ~BinarySearchTree();
};

#endif
