#include <iostream>
#include <chrono>

using namespace std;

int Partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for(int j = p; j <= r - 1; j++)
    {
        if(A[j] < x)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void QuickSort(int A[], int p, int r)
{
    if(p < r)
    {
        int q = Partition(A, p, r);

        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
}

int main() {
    int A[] = {10, 3, 2, 5, 9, 1, 7, 8, 4, 6};

    auto s = chrono::high_resolution_clock::now();
    QuickSort(A, 0, (sizeof(A)/sizeof(A[0]) - 1));
    auto f = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = f - s;

    cout<<"Sorted Array...\n";
    for(int e : A)
        printf("%d ", e);
    cout<<"\nTime taken for Quick Sort Algorithm (ms) :"<<elapsed.count() * 1000.0<<endl;


    return 0;
}