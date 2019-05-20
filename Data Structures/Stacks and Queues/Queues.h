#ifndef QUEUES_H
#define QUEUES_H

template <typename T>
class Queue {
private:
    int front_idx, back_idx, capacity;
    T *A;
public:
    Queue() capacity(50), front_idx(-1), back_idx(-1) {
        A = new T[capacity];
    }
    T Front() {
        if(!isEmpty())
            return A[front_idx];
        std::cout<<"Error. Queue is empty.\n";
    }
    T Back() {
        if(!isEmpty())
            return A[back_idx];
        std::cout<<"Error. Queue is empty.\n";
    }
    void Enqueue(const T& e);   //TODO.
    T Dequeue();                //TODO;
    bool isFull() {
        return (front == end == (capacity - 1));
    }
    bool isEmpty() {
        return (front == end == -1);
    }
    void showQueue();           //TODO;
    ~Queue();

};
#endif