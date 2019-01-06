#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

#define k 10
//O(n+k) Time Complexity.
//O(n+k) Space Complexity.

void CountSort(vector<int>&A)
{
    vector<int>B(A.size(), 0);
    vector<int>count(k+1, 0);

    for(int i=0; i<A.size(); i++)
        count[A[i]]++;

    for(int i=1; i<=k; i++)
        count[i] += count[i-1];

    for(int i=0; i<A.size(); i++)
    {
        B[count[A[i]] - 1] = A[i];
        count[A[i]]--;
    }

    A = B;
}


int main() {
    vector<int> A {10, 3, 2, 5, 9, 1, 7, 8, 4, 6};

    auto s = chrono::high_resolution_clock::now();
    CountSort(A);
    auto f = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = f - s;

    cout<<"Sorted Array...\n";
    for(int e : A)
        printf("%d ", e);
    cout<<"\nTime taken for Count Sort Algorithm (ms) :"<<elapsed.count() * 1000.0<<endl;


    return 0;
}