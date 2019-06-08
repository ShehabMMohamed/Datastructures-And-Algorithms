#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Stacks.h"
#include "Queues.h"

using namespace std;

int main() {
    srand(time(NULL));

    // Using Stack.
    Stack<int> S(50);

    // Pushing randomly generated elements into stack.
    for (int i = 0; i < 6; i++)
        S.push(rand() % 100);

    printf("Current top of stack is %d\n", S.top());
    // S.showStack();
    S.pop();
    S.pop();
    printf("Current top of stack is %d\n", S.top());
    // S.showStack();

    for (int i = 0; i < 5; i++)
        S.pop();

    std::cout<<endl;

    // Using Queue.
   Queue<char> Q;
   char c;

    // Pushing randomly generated chars into queue.
   for (int i = 0; i < 6; i++) {
        c = ((rand() % 26) + 'a');
        Q.Enqueue(c);
   }

   Q.queueFront(c);
   printf("Current front of queue is %c.\n", c);
   Q.Dequeue(c);
   printf("Removing element %c from queue.\n", c);
   Q.Dequeue(c);
   printf("Removing element %c from queue.\n", c);
   Q.queueFront(c);
   printf("Current front of queue is %c.\n", c);

   return 0;
}

