#ifndef STACKS_H
#define STACKS_H

class Stack {
private:
    int size, top_index;
    int *S;

public:
    Stack();

    Stack(int);

    void push(int);

    void pop();

    int top();

    bool isEmpty();

    bool isFull();

    void showStack();

    ~Stack();

};

#endif