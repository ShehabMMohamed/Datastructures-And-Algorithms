#include <iostream>
#include <string>
#include "Stacks.h"

// Implementing Stack class with a dynamically allocated array.
template<typename T>
Stack<T>::Stack() : top_index(-1) {
    S = new T[size];
}

template<typename T>
Stack<T>::Stack(int input_size) : top_index(-1) {
    size = input_size;
    S = new T[size];
}

template<typename T>
void Stack<T>::push(T e) {
    if (isFull())
        std::cout << "Stack is full. Can't push any more element.\n";
    else
        S[++top_index] = e;
}

template<typename T>
void Stack<T>::pop() {
    if (!isEmpty()) {
        S[top_index] = 0;
        top_index--;
    } else
        std::cout << "Stack is empty. Can't pop any more element.\n";
}

template<typename T>
T Stack<T>::top() {
    return isEmpty() ? -1 : S[top_index];
}

template<typename T>
bool Stack<T>::isEmpty() {
    return top_index == -1;
}

template<typename T>
bool Stack<T>::isFull() {
    return top_index == size - 1;
}

template<typename T>
void Stack<T>::showStack() {
    if (isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }
    for (int i = top_index; i >= 0; i--)
        std::cout << "[" << i << "] : " << S[i] << std::endl;
}

template<typename T>
Stack<T>::~Stack() {
    delete[] S;
}

template
class Stack<int>;

template
class Stack<char>;

template
class Stack<float>;