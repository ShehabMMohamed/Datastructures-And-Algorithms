#include <iostream>
#include "Data Structures/Stacks and Queues/Stacks.h"

using namespace std;

int main() {

    Stacks S = Stacks(25);
    int A[8] = {1, 3, 5, 7, 9, 15, 200, 100};

    for (int e : A)
        S.push(e);

    S.showStack();

    S.pop();
    S.pop();

    cout << "Current top of stack is [" << S.top() << "]\n";

    S.showStack();

    for (int i = 0; i < 8; i++)
        S.pop();

//    AVL_Tree tree = AVL_Tree();
////    for(int i=1; i<=10; i++)
////        tree.Insert(i);
//    tree.Insert(10);
//    tree.Insert(20);
//    tree.Insert(30);
//    tree.Insert(40);
//    tree.Insert(50);
//    tree.Insert(25);
//
//    tree.PreOrder();
//
//    cout << endl;


    return 0;
}

