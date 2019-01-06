#include <iostream>
#include <chrono>
using namespace std;

// Worst Case O(n^2), Average Case O(n^2), Best Case O(n).
void InsertionSort(int A[], int sz)
{
    int key, j;
    for(int i = 1; i < sz; i++)
    {
        key = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[++j] = key;
    }
}

int main() {
    int A[] = {10, 3, 2, 5, 9, 1, 7, 8, 4, 6};

    auto s = chrono::high_resolution_clock::now();
    InsertionSort(A, sizeof(A)/sizeof(A[0]));
    auto f = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = f - s;

    cout<<"Sorted Array...\n";
    for(int e : A)
        printf("%d ", e);
    cout<<"\nTime taken for Insertion Sort Algorithm (ms) :"<<elapsed.count() * 1000.0<<endl;


    return 0;
}