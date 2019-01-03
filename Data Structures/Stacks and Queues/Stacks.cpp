#include <iostream>
#include "Stacks.h"

// Implementing Stack class with a dynamically allocated array.
Stack::Stack() : top_index(-1) {
    S = new int[size];
}

Stack::Stack(int input_size) : top_index(-1) {
    size = input_size;
    S = new int[size];
}

void Stack::push(int e) {
    if (isFull())
        std::cout << "Stack is full. Can't push any more element.\n";
    else
        S[++top_index] = e;
}

void Stack::pop() {
    if (!isEmpty()) {
        S[top_index] = 0;
        top_index--;
    } else
        std::cout << "Stack is empty. Can't pop any more element.\n";
}

int Stack::top() {
    return isEmpty() ? -1 : S[top_index];
}

bool Stack::isEmpty() {
    return top_index == -1;
}

bool Stack::isFull() {
    return top_index == size - 1;
}

void Stack::showStack() {
    if (isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }
    for (int i = top_index; i >= 0; i--)
        std::cout << "[" << i << "] : " << S[i] << std::endl;
}

Stack::~Stack() {
    delete[] S;
}
