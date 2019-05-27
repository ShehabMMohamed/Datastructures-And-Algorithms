#ifndef HEAPS_H
#define HEAPS_H
#include <vector>

class MinHeap {
private:
    vector<int> V;
    int capacity;
    int count = 0;

public:
    MinHeap() {}l
    MinHeap(int size) : capacity(size) {};
    void BubbleUp(int);
    void BubbleDown(int);
    void Heapify();
    bool insert_key(int k);
    bool remove_key(int k);
    int retrieve_min();
    ~MinHeap() {};
};

class MaxHeap {
private:
    vector<int> V;
    int capacity;
    int count = 0;

public:
    MaxHeap() {};
    MaxHeap(int size) : capacity(size) {};
    void BubbleUp(int);
    void BubbleDown(int);
    void Heapify();
    bool insert_key(int k);
    bool remove_key(int k);
    int retrieve_max();
    ~MaxHeap() {};
};

#endif 
