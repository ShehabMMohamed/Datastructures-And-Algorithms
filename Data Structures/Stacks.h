#ifndef DATASTRUCTURES_MYSTACK_H
#define DATASTRUCTURES_MYSTACK_H

// Implementing Stack class with a dynamically allocated array.
class Stacks {
private:
    int size = 50;
    int top;
    int *S;

public:
    Stacks();

    Stacks(int);

    void push(int);

    void pop();

    int retrieve_top();

    bool isEmpty();

    bool isFull();

    void showStack();

    ~Stacks();

};

#endif //DATASTRUCTURES_MYSTACK_H
