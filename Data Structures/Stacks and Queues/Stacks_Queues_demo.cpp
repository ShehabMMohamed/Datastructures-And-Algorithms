#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Stacks.h"
#include "Queues.h"

using namespace std;

int main() {

    srand(time(NULL));

    Stack S = Stack(25);

    // Pushing randomly generated elements into stack.
    for (int i = 0; i < 9; i++)
        S.push(rand() % 100);

    S.showStack();

    S.pop();
    S.pop();

    cout << "Current top of stack is [" << S.top() << "]\n";

    S.showStack();

    for (int i = 0; i < 8; i++)
        S.pop();

    return 0;
}

