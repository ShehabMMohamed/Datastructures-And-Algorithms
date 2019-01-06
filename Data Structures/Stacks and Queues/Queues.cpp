#include "Queues.h"
#include <iostream>

Queue::Queue() : capacity(25), front(-1), back(-1) {
    A = new int[capacity];
};

int Queue::Back() {
    if (!isEmpty())
        return A[back];
    cout << "Error. Queue is empty.\n";
    return -1;
}

int Queue::Front() {
    if (!isEmpty())
        return A[front];
    cout << "Error. Queue is empty.\n";
    return -1;
}

bool Queue::isEmpty() {
    return (front == end == -1);
}

bool Queue::isFull() {
    return (front == end == capacity - 1);
}

void Queue::Enqueue(int element) {
    if (isFull()) {
        cout << "Error. Queue is full.\n";
        return;
    }
    //TODO.
}

int Queue::Dequeue() {
    if (isEmpty()) {
        cout << "Error. Queue is empty.\n";
        return -1;
    }
    //TODO.
}
