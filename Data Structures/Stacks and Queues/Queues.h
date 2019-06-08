#ifndef QUEUES_H
#define QUEUES_H

template <typename T>
class Queue {
private:
    int front, back, capacity, size;
    T *q;
public:
    Queue() : size(0), capacity(125), front(1), back(0) { q = new T[capacity]; }
    void Enqueue(const T& e) {
        if(isFull())
            std::cout<<"Queue is Full. \n";
        else {
            std::cout << "(" << e << ") enqueued.\n";
            back = (back + 1) % capacity;
            q[back] = e;
            size++;
        }
    }
    void Dequeue(T& e) {
        if(isEmpty())
            std::cout<<"Queue is Empty. \n";
        else {
            e = q[front];
            std::cout << "(" << e << ") dequeued.\n";
            front = (front + 1) % capacity;
            size--;
        }
    }
    void queueFront(T& e) {
        if(isEmpty())
            std::cout<<"Queue is Empty. \n";
        else
            e = q[front];
    }
    bool isFull() { return (size == capacity); }
    bool isEmpty() { return (size == 0); }
    ~Queue() {  delete[] q; }

};

#endif