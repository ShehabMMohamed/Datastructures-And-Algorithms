#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

void BinarySearchTree::Search(const int& key) {
    if(_search(root, key))
        std::cout<<"Node with key {"<<key<<"} exists.\n";
    else
        std::cout<<"Node with key {"<<key<<"} does not exist.\n";
    return;
}

bool BinarySearchTree::_search(TreeNode* node, const int& key) {
    if(node == nullptr)
        return false;
    if(node->key == key)    return true;
    
    if(key > node->key)
        return _search(node->right, key);
    
    return _search(node->left, key);
}

void BinarySearchTree::Add(const int& key) {
    root = _insert(root, key);
}

TreeNode* BinarySearchTree::_insert(TreeNode* node, const int& key) {
    if(node == nullptr)
        return new TreeNode(key);
    
    if(key > node->key)
        node->right = _insert(node->right, key);
    
    else if(key < node->key)
        node->left = _insert(node->left, key);
    
    return node;
}

void BinarySearchTree::Delete(const int& key) {
    _delete(root, key);
}

TreeNode* BinarySearchTree::_delete(TreeNode* node, const int& key) {
    if(!node)
        return node;  // nullptr.
    
    if(key > node->key)
        node->right = _delete(node->right, key);
    
    else if (key < node->key)
        node->left = _delete(node->left, key);
    
    else {
        // Three cases to consider.
        // I have only right child. (1)
        //      (5)
        //    /   \
        //   NULL  (7)
        if(node->left == nullptr) {
            TreeNode* RightChild = node->right;
            delete node;
            return RightChild;
        }
        // I have only left child.  (2)
        //      5
        //    /   \
        //   3     NULL
        if(node->right == nullptr) {
            TreeNode* LeftChild = node->left;
            delete node;
            return LeftChild;
        }
        // I have two children, I need to find either a Sucessor/Predecessor to take
        // the deleted node's new location.
        TreeNode* Sucessor = node->right;
        
        while(Sucessor->left != nullptr)
            Sucessor = Sucessor->left;
        
        std::swap(node->key, Sucessor->key);
        node->right = _delete(node->right, key);
    }
    
    return node;
    
}

int BinarySearchTree::Minimum() {
    TreeNode* min_node = _minimum(root);
    return min_node ? min_node->key : -1;
}

int BinarySearchTree::Maximum() {
    TreeNode* max_node = _maximum(root);
    return max_node ? max_node->key : -1;
}

TreeNode* BinarySearchTree::_minimum(TreeNode* node) {
    if(!node || !node->left)
        return node;
    return _minimum(node->left);
}

TreeNode* BinarySearchTree::_maximum(TreeNode* node) {
    if(!node || !node->right)
        return node;
    return _maximum(node->right);
}

void BinarySearchTree::PreOrder() {
    printf("Visiting Tree nodes in PreOrder.\n");
    _pre_order(root);
    printf("\n");
}
void BinarySearchTree::InOrder() {
    printf("Visiting Tree nodes in InOrder.\n");
    _in_order(root);
    printf("\n");
}
void BinarySearchTree::PostOrder() {
    printf("Visiting Tree nodes in PostOrder.\n");
    _post_order(root);
    printf("\n");
}

void BinarySearchTree::_pre_order(TreeNode* node) {
    if(!node)   return;
    std::cout<<node->key<<" ";
    _pre_order(node->left);
    _pre_order(node->right);
}

void BinarySearchTree::_in_order(TreeNode* node) {
    if(!node)   return;
    _in_order(node->left);
    std::cout<<node->key<<" ";
    _in_order(node->right);
}

void BinarySearchTree::_post_order(TreeNode* node) {
    if(!node)   return;
    _post_order(node->left);
    _post_order(node->right);
    std::cout<<node->key<<" ";
}

void BinarySearchTree::_destroy_recusrive(TreeNode* node) {
    if(node != nullptr) {
        if(node->left)  _destroy_recusrive(node->left);
        if(node->right) _destroy_recusrive(node->right);
        printf("Deleting Node %d\n", node->key);
        delete node;
    }
}

BinarySearchTree::~BinarySearchTree() {
    try {
        std::cout<<"Destroying Tree nodes.\n";
        _destroy_recusrive(root);
    }
    catch(std::exception& e) {
        std::cout<<"Exception Occured: "<<e.what()<<"\n";
    }
}
