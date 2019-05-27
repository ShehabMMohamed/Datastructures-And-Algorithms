#ifndef REDBLACKTREES_H
#define REDBLACKTREES_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void inline swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Red Black Tree Node.
class TreeNode {
public:
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    int key;
    int color;     // Red : 1 | Black : 0
    TreeNode(int item) : key(item), color(1) {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

// Red Black Tree [Based on C.L.R.S.]
class RedBlackTree {

private:
    TreeNode *root;

    TreeNode* _insert(TreeNode *root, TreeNode* node) {
        // Normal BST Operation.
        if(!root)   return node;
        if(node->key < root->key) {
            root->left = _insert(root->left, node);
            root->left->parent = root;
        }
        else if(node->key > root->key) {
            root->right = _insert(root->right, node);
            root->right->parent = root;
        }
        return root;
    }

    // missing delete feature.

    void _search(TreeNode *root, const int& item) {
        if(!root) {
            std::cout<<"Key {"<<item<<"} not found in RBT.\n";
            return;
        }
        if(root->key == item) {
            std::cout<<"Key {"<<item<<"} exists in RBT.\n";
        }
        else if(item < root->key)
            _search(root->left, item);
        else if(item > root->key)
            _search(root->right, item);
    }

    void _recolor(TreeNode *&node, const std::string& c) { node->color = (c == "BLACK") ? 0 : 1 ;}
    void RB_FixUp(TreeNode *&root, TreeNode *&N) {
        TreeNode *P = NULL, *G = NULL;  // P : Parent | G : GrandParent

        while( (N != root) && (N->color !=0) && (N->parent->color == 1) ) {
            P = N->parent;
            G = N->parent->parent;
            // Case 1 : P is left child of G.
            if(P == G->left) {
                // U is right child of G.
                TreeNode *U = G->right;

                // Case 1A : Uncle is Red.
                if(U && U->color == 1) {
                    _recolor(G, "RED");
                    _recolor(P, "BLACK");
                    _recolor(U, "BLACK");
                    N = G;
                }
                // Case 1B : Uncle is Black.
                else {
                    // N is right child of P. (Left Right Case)
                    if(N == P->right) {
                        RotateLeft(P);
                        N = P;
                        P = N->parent;
                    }
                    // N is left child of P. (Left Left Case)
                    RotateRight(G);
                    swap(P->color, G->color);
                    N = P;
                }
            }
            // Case 2 : P is right child of G.
            else {
                // U is left child of G.
                TreeNode *U = G->left;

                // Case 2A : Uncle is Red.
                if(U && U->color == 1) {
                    _recolor(G, "RED");
                    _recolor(P, "BLACK");
                    _recolor(U, "BLACK");
                    N = G;
                }
                // Case 2B : Uncle is Black.
                else {
                    // N is left child of P. (Right Left Case)
                    if(N == P->left) {
                        RotateRight(P);
                        N = P;
                        P = N->parent;
                    }
                    // N is right child of P. (Right Right Case)
                    RotateLeft(G);
                    swap(P->color, G->color);
                    N = P;
                }
            }
        }
        _recolor(root, "BLACK");
    }

    void RotateRight(TreeNode *&y) {
        TreeNode *x = y->left;
        y->left = x->right;

        if(y->left) 
            y->left->parent = y;

        x->parent = y->parent;

        if(!y->parent)
            root = x;
        else if(y == y->parent->left)   // left child.
            y->parent->left = x;
        else                            // right child.
            y->parent->right = x;

        x->right = y;
        y->parent = x;
    }

    void RotateLeft(TreeNode *&x) {
        TreeNode *y = x->right;
        x->right = y->left;

        if(x->right)
            x->right->parent = x;

        y->parent = x->parent;

        if(!x->parent)
            root = y;
        else if(x == x->parent->left)   // left child.
            x->parent->left = y;
        else                            // right child.
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void InOrder(TreeNode *root) {
        int n = 0;
        if(!root)   return;
        InOrder(root->left);
        std::cout<<root->key<<" ";
        InOrder(root->right);
    }

    void Print2D(TreeNode *root, int spaces, std::ofstream& file, bool flag) {
        const int count = 8;
        if(!root)   return;
        spaces += count;
        Print2D(root->right, spaces, file, false);
        file<<std::endl;
        for(int i = count; i < spaces; i++)
            file<<" ";
        if(flag)
            file<<"->[B]("<<root->key<<")"<<std::endl;
        else {
            if(root->color == 0)
                file<<"[B]("<<root->key<<")"<<std::endl;
            else
                file<<"[R]("<<root->key<<")"<<std::endl;
        }
        Print2D(root->left, spaces, file, false);
    }

public:
    RedBlackTree() : root(NULL) {};
    void InsertKey(const int& item) {
        TreeNode *node = new TreeNode(item);
        root = _insert(root, node);
        RB_FixUp(root, node);
    }
    void SearchKey(const int& item) { _search(root, item); }

    // void DeleteKey(const T& item) { }

    void InOrderTraversal() {
        std::cout<<"InOrder of Tree...\n";
        InOrder(root);
        std::cout<<"\n";
    }

    void SaveTree() {
        std::ofstream file;
        file.open("tree_display.txt");
        std::cout<<"2D Display Tree written in (tree_display.txt)...\n";
        Print2D(root, 0, file, true);
        file.close();
        std::cout<<"\n";

    }
    ~RedBlackTree() {};

};


#endif 
