#ifndef QUEUES_H
#define QUEUES_H

// Circular Array Implementation.
class Queue {
private:
    int front, back, capacity;
    int *A;
public:
    Queue();

    int Front();

    int Back();

    void Enqueue(int);

    int Dequeue();

    bool isFull();

    bool isEmpty();

    ~Queue();

};

#endif
