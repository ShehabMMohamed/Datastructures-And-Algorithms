void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Terrible for large collection of data, efficient only if list is already sorted.
// Worst Case O(n^2), Average Case O(n^2), Best Case O(n)
void BubbleSort(int A[], int sz)
{
    bool swapped;       // This optimization helps to figure out if actual swapping occurred or not in the inner loop.
                        // If it never occurred, then the list is already sorted. O(n) best case.
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Worst Case O(n^2), Average Case O(n^2), Best Case O(n).
void InsertionSort(int A[], int sz)
{
    int j, key;
    for (int i = 1; i < sz; i++)
    {
        j = i - 1;
        key = A[i];
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[++j] = key;
    }
}

// Worst Case O(n^2), Average Case O(n^2), Best Case O(n^2)
void SelectionSort(int A[], int sz)
{
    int min_indx;
    for(int i=0; i<sz-1; i++)
    {
        min_indx = i;
        for (int j = i + 1; j < sz; j++)
            if (A[min_indx] > A[j]) min_indx = j;

        swap(A[min_indx], A[i]);
    }
}

void Merge(int A[], int l, int m, int r) {
    int N1 = m - l + 1;
    int N2 = r - m;
    int L[N1], R[N2];
    int i, j, k = 0;

    for (i = 0; i < N1; i++)
        L[i] = A[i + l];

    for (j = 0; j < N2; j++)
        R[j] = A[j + m + 1];

    for (i = 0, j = 0; i < N1 && j < N2; k++)
        L[i] < R[j] ? A[l + k] = L[i++] : A[l + k] = R[j++];

    while (i < N1)
        A[l + (k++)] = L[i++];

    while (j < N2)
        A[l + (k++)] = R[j++];
}

void MergeSort(int A[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(A, l, m);
        MergeSort(A, m + 1, r);

        Merge(A, l, m, r);
    }
}

void QuickSort();
int Partition();