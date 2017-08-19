void swap(int*a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Terrible for large collection of data, efficient only if list is already sorted.
// Worst Case O(n^2), Average Case O(n^2), Best Case O(n)
void BubbleSort(int Arr[], int sz)
{
    bool swapped;       // This optimization helps to figure out if actual swapping occurred or not in the inner loop.
                        // If it never occurred, then the list is already sorted. O(n) best case.
    for(int i=0; i<sz - 1; i++) {
        swapped = false;
        for (int j = 0; j < sz - i - 1; j++) {
            if (Arr[i] > Arr[j]) {
                swap(&Arr[i], &Arr[j]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}

// Worst Case O(n^2), Average Case O(n^2), Best Case O(n).
void InsertionSort(int Arr[], int sz)
{
    int key, j;
    for(int i = 1; i<sz; i++)
    {
        key = Arr[i];
        j = i - 1;
        while(j>= 0 && Arr[j] > key)
        {
            Arr[j++] = Arr[j];
            j--;
        }
        Arr[j++] = key;
    }

}

// Worst Case O(n^2), Average Case O(n^2), Best Case O(n^2)
void SelectionSort(int Arr[], int sz)
{
    int Min;
    for(int i=0; i<sz-1; i++)
    {
        Min = i;
        for(int j = i + 1; j<sz; j++)
            if(Arr[j]<Arr[Min])
                Min = j;
        if(Min != i)
            swap(&Arr[Min], &Arr[i]);
    }

}

void MergeSort();
void HeapSort();
void Merge();
void QuickSort();
int Partition();