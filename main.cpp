#include <iostream>
//#include <unordered_set>
//#include <unordered_map>
//#include <queue>
//#include "Data Structures/Stacks.h"
#include "Advanced Data Structures/AVL_Tree.h"
//
//#include "Algorithms/sorting_algorithms.cpp"
using namespace std;

int main() {

    AVL_Tree tree = AVL_Tree();
//    for(int i=1; i<=10; i++)
//        tree.Insert(i);
    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(30);
    tree.Insert(40);
    tree.Insert(50);
    tree.Insert(25);

    tree.PreOrder();

    cout << endl;
//    Stacks S1 = Stacks(25);
//    for (int i = 0; i < 5; i++)
//        S1.push(10 + i);
//    S1.showStack();
//    cout << endl;
//    S1.pop();
//    S1.pop();
//    S1.pop();
//    S1.pop();
//    S1.pop();
//    S1.pop();
//    S1.showStack();
//    cout << endl;
//    cout << "Stack empty? -> " << boolalpha<<S1.isEmpty() << endl;
//    cout << "Stack full? -> " << boolalpha<<S1.isFull() << endl;


    return 0;
}

