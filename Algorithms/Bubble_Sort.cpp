#include <iostream>
#include <chrono>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Terrible for large collection of data, efficient only if list is already sorted.
// Worst Case O(n^2), Average Case O(n^2), Best Case O(n)
void BubbleSort(int A[], int sz) {
    bool swapped = false;   // This optimization helps to figure out if actual swapping occurred or not in the inner loop.
    // If it never occurred, then the list is already sorted. O(n) best case.

    for (int i = 0; i < sz - 1; i++) {
        for (int j = 0; j < sz - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    int A[] = {10, 3, 2, 5, 9, 1, 7, 8, 4, 6};

    auto s = chrono::high_resolution_clock::now();
    BubbleSort(A, sizeof(A) / sizeof(A[0]));
    auto f = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = f - s;

    cout << "Sorted Array...\n";
    for (int e : A)
        printf("%d ", e);
    cout << "\nTime taken for Bubble Sort Algorithm (ms) :" << elapsed.count() * 1000.0 << endl;


    return 0;
}