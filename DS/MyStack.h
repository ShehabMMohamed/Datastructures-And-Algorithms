#ifndef DATASTRUCTURES_MYSTACK_H
#define DATASTRUCTURES_MYSTACK_H

// Implementing Stack class with a dynamically allocated array.
class MyStack {
private:
    int size = 50;
    int top;
    int *S;

public:
    MyStack();

    MyStack(int);

    void push(int);

    int pop();

    bool isEmpty();

    bool isFull();

    void showStack();

    ~MyStack();

};


// Implementing Stack class with a linked list.
class MyStack2 {
private:
    struct StackNode {
        int value;
        StackNode *next;
    };
    StackNode *root;
    int size = 50;
    int top;
    int *S;

public:
    MyStack2();

    MyStack2(int);

    void push(int);

    int pop();

    bool isEmpty();

    bool isFull();

    void showStack();

    ~MyStack2();

};

#endif //DATASTRUCTURES_MYSTACK_H
