#include <iostream>
using namespace std;

// Min-Heap based implementation.
class PriorityQueue {
private:
    int *A;
    int capacity;
    int size;

    int Parent(int i) { return (i - 1) / 2; }
    int Left(int i) { return (i * 2) + 1; }
    int Right(int i) { return (i * 2) + 2; }
    // recursive
    void HeapifyUp(int i) {
        int parent_i = Parent(i);
        if( i >= 0 && A[i] < A[parent_i]) {
            swap(A[i], A[parent_i]);
            HeapifyUp(parent_i);
        }
    }
    // recursive
    void HeapifyDown(int i) {
        int left_i = Left(i);
        int right_i = Right(i); 
        int smallest = i;

        if(left_i < size && A[left_i] < A[i]) {
            smallest = left_i;
        }
        if(right_i < size && A[right_i] < A[smallest]) {
            smallest = right_i;
        }
        if( smallest != i ) {
            swap(A[i], A[smallest]);
            HeapifyDown(smallest);
        }
    }

public:
    PriorityQueue() : capacity(6), size(0) {
        A = new int[capacity];
    }
    bool IsFull() { return size == capacity; }
    bool IsEmpty() { return size == 0; }
    void Push(int element) {
        if(IsFull()) {
            cout<<"PQ is currently full."<<endl;
            return;
        }
        cout<<"Pushing element - "<<element<<endl;
        A[size] = element;
        size++;
        int index = size - 1;
        HeapifyUp(index);
    }

    void Pop() {
        if(IsEmpty()) {
            cout<<"PQ is currently empty."<<endl;
            return;
        }
        A[0] = A[size - 1];
        size--;
        HeapifyDown(0);
    }

    int Top() {
        if(IsEmpty()) {
            cout<<"PQ is currently empty."<<endl;
            return -1;
        }
        return A[0];
    }
    ~PriorityQueue() {
        delete []A;
    }
};
