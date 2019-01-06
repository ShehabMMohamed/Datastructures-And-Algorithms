#include <iostream>
#include <chrono>

using namespace std;

void Heapify(int A[], int n, int i)
{
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if(left < n && A[left] > A[largest])
        largest = left;
    if(right < n && A[right] > A[largest])
        largest = right;

    if(largest != i)
    {
        swap(A[largest], A[i]);
        Heapify(A, n, largest);
    }
}

void HeapSort(int A[], int n)
{
    // build max heap
    for(int i=n/2 - 1; i>=0; i--)
        Heapify(A, n, i);

    //Sort
    for(int i=n-1; i>=0; i--)
    {
        swap(A[0], A[i]);	// swap first element with last element.
        Heapify(A, i, 0);
    }
}

int main() {
    int A[] = {10, 3, 2, 5, 9, 1, 7, 8, 4, 6};

    auto s = chrono::high_resolution_clock::now();
    HeapSort(A, sizeof(A)/sizeof(A[0]));
    auto f = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = f - s;

    cout<<"Sorted Array...\n";
    for(int e : A)
        printf("%d ", e);
    cout<<"\nTime taken for Heap Sort Algorithm (ms) :"<<elapsed.count() * 1000.0<<endl;


    return 0;
}