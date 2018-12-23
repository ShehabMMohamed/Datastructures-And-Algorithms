#include <iostream>
#include "Stacks.h"

// Implementing Stack class with a dynamically allocated array.
Stacks::Stacks() : top(-1) {
    S = new int[size];
}

Stacks::Stacks(int input_size) : top(-1) {
    size = input_size;
    S = new int[size];
}

void Stacks::push(int v) {
    if (!isFull())
        S[++top] = v;
}

void Stacks::pop() {
    if (!isEmpty()) {
        int v = S[top];
        top--;
    }
}

int Stacks::retrieve_top() {
    return isEmpty() ? -1 : S[top];
}

bool Stacks::isEmpty() {
    return top == -1;
}

bool Stacks::isFull() {
    return top == size - 1;
}

void Stacks::showStack() {
    if (isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }
    for (int i = 0; i <= top; i++)
        std::cout << "[" << i << "] : " << S[i] << std::endl;
}

Stacks::~Stacks() {
    delete[] S;
}
