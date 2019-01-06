#include <iostream>
#include <chrono>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Worst Case O(n^2), Average Case O(n^2), Best Case O(n^2)
void SelectionSort(int A[], int sz)
{
    int min_indx;
    for(int i=0; i<sz-1; i++)
    {
        min_indx = i;
        for(int j=i+1; j<sz; j++)
        {
            if(A[j] < A[min_indx])
                min_indx = j;
        }
        swap(A[min_indx], A[i]);
    }
}

int main() {
    int A[] = {10, 3, 2, 5, 9, 1, 7, 8, 4, 6};

    auto s = chrono::high_resolution_clock::now();
    SelectionSort(A, sizeof(A)/sizeof(A[0]));
    auto f = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = f - s;

    cout<<"Sorted Array...\n";
    for(int e : A)
        printf("%d ", e);
    cout<<"\nTime taken for Selection Sort Algorithm (ms) :"<<elapsed.count() * 1000.0<<endl;


    return 0;
}