#include <iostream>
#include <chrono>

using namespace std;

void Merge(int A[], int l, int m, int r)
{
    int i, j, k=0;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];
    for(i = 0, j = 0; i < n1 && j < n2; k++)
        L[i] <= R[j] ? A[l+k] = L[i++] : A[l+k] = R[j++];
    while(i < n1)
        A[l+(k++)] = L[i++];
    while(j < n2)
        A[l+(k++)] = R[j++];
}

void MergeSort(int A[], int left, int right)
{
    if(left < right)
    {
        int middle = left + (right-left) / 2;
        MergeSort(A, left, middle);
        MergeSort(A, middle+1, right);
        Merge(A, left, middle, right);
    }
}

int main() {
    int A[] = {10, 3, 2, 5, 9, 1, 7, 8, 4, 6};

    auto s = chrono::high_resolution_clock::now();
    MergeSort(A, 0, (sizeof(A)/ sizeof(A[0])) - 1);
    auto f = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = f - s;

    cout<<"Sorted Array...\n";
    for(int e : A)
        printf("%d ", e);
    cout<<"\nTime taken for Merge Sort Algorithm (ms) :"<<elapsed.count() * 1000.0<<endl;

    return 0;
}