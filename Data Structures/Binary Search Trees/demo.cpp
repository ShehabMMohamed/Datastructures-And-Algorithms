#include <iostream>
#include "BinarySearchTrees.h"
using namespace std;



int main() {
    BST mytree = BST();
    int my_values[] = {10, 7, 4, 8, 12, 11};
    int n = sizeof(my_values)/sizeof(my_values[0]);
    
    for(int i = 0; i < n; i++) {
        mytree.InsertNode(my_values[i]);
    }
    
    // cout<<"Minimum value of tree is : "<<mytree.Minimum()<<endl;
    mytree.InOrder();
    
    return 0;
}
