#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Stacks.h"
//#include "Queues.h"

using namespace std;

int main() {
    srand(time(NULL));

    // Using Stack.
    Stack<int> S = Stack(25);

    // Pushing randomly generated elements into stack.
    for (int i = 0; i < 9; i++)
        S.push(rand() % 100);

    printf("Current top of stack is %d\n", S.top());
    S.showStack();
    S.pop();
    S.pop();
    printf("Current top of stack is %d\n", S.top());
    S.showStack();

    for (int i = 0; i < 8; i++)
        S.pop();

    // Using Queue.
//    Queue Q = Queue();
//
//    for (int i = 0; i < 14; i++)
//        Q.Enqueue(rand() % 100);
//
//    Q.showQueue();
//    printf("Current front of queue is %d\n", Q.Front());
//    printf("Removing element %d from queue\n", Q.Dequeue());
//    printf("Current front of queue is %d\n", Q.Front());
//    printf("Current back of queue is %d\n", Q.Back());

    return 0;
}

