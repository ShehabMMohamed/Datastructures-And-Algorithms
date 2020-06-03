#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

/*         (root)
            (10)
           /    \
        (7)     (12)
        / \    /
      (4) (8) (11)
 */

// Depth-First Search (DFS)
// 1) InOrder: 4, 7, 8, 10, 11, 12     left, root, right
// 2) PreOrder: 10, 7, 4, 8, 12, 11    root, left, right
// 3) PostOrder: 4, 8, 7, 11, 12, 10   left, right, root



int main() {
    BinarySearchTree mytree = BinarySearchTree();
    
    // test case
    int my_values[] = {10, 7, 4, 8, 12, 11};
    int n = sizeof(my_values)/sizeof(my_values[0]);
    
    for(int i = 0; i < n; i++) {
        mytree.Add(my_values[i]);
    }
    
    cout<<"Minimum value of tree is : "<<mytree.Minimum()<<endl;
    cout<<"Maximum value of tree is : "<<mytree.Maximum()<<endl;
    

    mytree.PreOrder();
    mytree.InOrder();
    mytree.PostOrder();

    int some_keys[] = {8, 9, 10};
    for(int key : some_keys) {
        mytree.Search(key);
    }
    
    mytree.Delete(20);
    mytree.Delete(4);
    
    mytree.InOrder();

    
    return 0;
}
