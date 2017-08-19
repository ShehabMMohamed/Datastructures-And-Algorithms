#include <iostream>
#include "DS/MyStack.h"

using namespace std;

int main() {

    MyStack S1 = MyStack(25);
    for (int i = 0; i < 5; i++)
        S1.push(10 + i);
    S1.showStack();
    cout << endl;
    S1.pop();
    S1.pop();
    S1.showStack();
    cout << endl;
    cout << "Stack empty? -> " << S1.isEmpty() << endl;
    cout << "Stack full? -> " << S1.isFull() << endl;

    //TODO:Not testet yet. need to finish methods definition.
    MyStack2 S2 = MyStack2(25);
    for (int i = 0; i < 5; i++)
        S2.push(10 + i);
    S2.showStack();
    cout << endl;
    S2.pop();
    S2.pop();
    S2.showStack();
    cout << endl;
    cout << "Stack empty? -> " << S2.isEmpty() << endl;
    cout << "Stack full? -> " << S2.isFull() << endl;

    return 0;
}

