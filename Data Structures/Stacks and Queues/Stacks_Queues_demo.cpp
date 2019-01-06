#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Stacks.h"
#include "Queues.h"

using namespace std;
srand(time(NULL));

int main() {

    // Using Stack.
    Stack S = Stack(25);

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
    Queue Q = Queue();

    return 0;
}

