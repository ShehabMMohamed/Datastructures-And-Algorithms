#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main() {
    // Min Heap
    // 5, 3, 2, 6, 1
    PriorityQueue PQ;
    int A[] = {5, 3, 2, 6, 1};
    int N = sizeof(A) / sizeof(A[0]);
    for(int i = 0; i < N; i++) {
        PQ.Push(A[i]);
    }
    
    cout<<"Top of PQ is: "<<PQ.Top()<<endl;     // 1
    PQ.Pop();  // 1
    cout<<"Top of PQ is: "<<PQ.Top()<<endl;     // 2
    PQ.Pop();   // 2
    cout<<"Top of PQ is: "<<PQ.Top()<<endl;     // 3
    PQ.Pop();   // 3
    cout<<"Top of PQ is: "<<PQ.Top()<<endl;     // 5
    PQ.Pop();   // 5
    cout<<"Top of PQ is: "<<PQ.Top()<<endl;     // 6
    PQ.Pop();   // 6
    PQ.Pop();   // No more elements to pop, empty.

    return 0;
}