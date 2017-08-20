#ifndef DATASTRUCTURES_MYHEAP_H
#define DATASTRUCTURES_MYHEAP_H

#include <vector>

using namespace std;

//TODO: Start with Queue and Heap.
class MyMinHeap {
private:
    vector<int> V;
    int capacity;
    int count = 0;

public:
    MyMinHeap();

    MyMinHeap(int size);

    void BubbleUp(int);

    void BubbleDown(int);

    void Heapify();

    bool insert_key(int k);

    bool remove_key(int k);

    int retrieve_min();

    ~MyMinHeap();

};

class MyMaxHeap {
private:
    vector<int> V;
    int capacity;
    int count = 0;

public:
    MyMaxHeap();

    MyMaxHeap(int size);

    void BubbleUp(int);

    void BubbleDown(int);

    void Heapify();

    bool insert_key(int k);

    bool remove_key(int k);

    int retrieve_max();

    ~MyMaxHeap();

};

#endif //DATASTRUCTURES_MYHEAP_H
