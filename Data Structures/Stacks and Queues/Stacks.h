#ifndef STACKS_H
#define STACKS_H

template<typename T>
class Stack {
private:
    int size = 50, top_index;
    T *S;

public:
    Stack();

    Stack(int);

    void push(T);

    void pop();

    T top();

    bool isEmpty();

    bool isFull();

    void showStack();

    ~Stack();

};

#endif