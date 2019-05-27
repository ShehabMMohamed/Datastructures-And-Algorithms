#ifndef STACKS_H
#define STACKS_H

template<typename T>
class Stack {
private:
    int size = 50, top_index;
    T *S;

public:
    Stack() : top_index(-1) {
        S = new T[size];
    }

    Stack(int input_size) : top_index(-1) {
        size = input_size;
        S = new T[size];
    }

    void push(T e) {
        if (isFull())
            std::cout << "Stack is full. Can't push any more element.\n";
        else {
            S[++top_index] = e;
            std::cout << "Pushing " << e << " to Stack\n";
        }
    }

    void pop() {
        if (!isEmpty()) {
            std::cout<<"Popping from Stack.\n";
            S[top_index] = 0;
            top_index--;
        } else
            std::cout << "Stack is empty. Can't pop any more element.\n";
    }

    T top() {
        return isEmpty() ? -1 : S[top_index];
    }

    bool isEmpty() {
        return top_index == -1;
    }

    bool isFull() {
        return top_index == size - 1;
    }

    void showStack() {
        if (isEmpty()) {
            std::cout << "Stack is Empty." << std::endl;
            return;
        }
        for (int i = top_index; i >= 0; i--)
            std::cout << "[" << i << "] : " << S[i] << std::endl;
    }

    ~Stack() {
        delete[] S;
    }

};

#endif