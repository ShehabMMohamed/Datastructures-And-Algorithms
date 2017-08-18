#include <iostream>
#include "MyStack.h"

// Implementing Stack class with a dynamically allocated array.
MyStack::MyStack() : top(-1) {
    S = new int[size];
}

MyStack::MyStack(int input_size) : top(-1) {
    this->size = input_size;
    S = new int[size];
}

void MyStack::push(int v) {
    if (!isFull())
        S[++top] = v;
}

int MyStack::pop() {
    if (!isEmpty()) {
        int v = S[top];
        top--;
        return v;
    }
}

bool MyStack::isEmpty() {
    return top == -1;
}

bool MyStack::isFull() {
    return top == size - 1;
}

void MyStack::showStack() {
    if (isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }
    for (int i = 0; i < top; i++)
        std::cout << "[" << i << "] : " << S[i] << std::endl;
}

MyStack::~MyStack() {
    delete[] S;
}