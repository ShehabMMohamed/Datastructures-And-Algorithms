#include <iostream>
#include "Stacks.h"

// Implementing Stack class with a dynamically allocated array.
Stacks::Stacks() : top(-1) {
    S = new int[size];
}

Stacks::Stacks(int input_size) : top(-1) {
    this->size = input_size;
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

// Implementing Stack class with a linked list.
MyStack2::MyStack2() : top(0) {}

MyStack2::MyStack2(int input_size) : top(0), capacity(input_size) {}

StackNode *MyStack2::createStackNode(int data) {
    StackNode *newNode = new StackNode;
    newNode->value = data;
    return newNode;
}

void MyStack2::push(int v) {
    StackNode *newNode = createStackNode(v);
    if (isEmpty()) {
        root = newNode;
        return;
    }
    if (isFull())
        return;

    // Not correct.
    newNode->next = root;
    root = newNode;
}

void MyStack2::pop() {
    if (isEmpty())
        return;
    StackNode *temp = root;
    root = root->next;
    delete temp;
}

int MyStack2::retrieve_top() {

}

bool MyStack2::isEmpty() {
    return top == 0;
}

bool MyStack2::isFull() {
    return top == capacity - 1;
}

void MyStack2::showStack() {

}

MyStack2::~MyStack2() {

}