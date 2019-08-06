#ifndef HEAPS_H
#define HEAPS_H
#include <vector>

template<typename T>
class MinHeap {
private:
    std::vector<T> V;
    int capacity;
    int count = 0;

public:
    MinHeap() {};
    MinHeap(std::vector<T> vec) {
        for(const T& item : vec)
            push(item);
    }
    void push(const T& item) {

    }
    void pop() {

    }
    T top() {

    }
    void HeapSort() {

    }
    void Heapify() {

    }
    ~MinHeap() {};
};

template<typename T>
class MaxHeap {
private:
    std::vector<int> V;
    int capacity;
    int count = 0;

public:
    MaxHeap() {};

    void BubbleUp(int);
    void BubbleDown(int);
    void Heapify();
    bool insert_key(int k);
    bool remove_key(int k);
    int retrieve_max();
    ~MaxHeap() {};
};

#endif 
