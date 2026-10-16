#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int first, int last)
{
    int pivot = arr[first];
    int low = first + 1;
    int high = last;
    while (high > low)
    {
        while (arr[high] > pivot)
        {
            high--;
        }
        while (high >= low && arr[low] <= pivot)
        {
            low++;
        }
        if (high > low)
        {
            swap(arr[high], arr[low]);
        }
    }
    if (arr[high] <= pivot) // not stable if remove the equal assign it will be stable
    {
        arr[first] = arr[high];
        arr[high] = pivot;
        return high;
    }
    else

        return first;
}
int partition2(int arr[], int fist, int last)
{
}
void quicksort(int arr[], int first, int last)
{
    if (last <= first)
        return;
    else
    {
        int pivotindex = partition(arr, first, last);
        quicksort(arr, first, pivotindex - 1);
        quicksort(arr, pivotindex + 1, last);
    }
}
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int partitionindex = partition(array, 0, 8);

    quicksort(array, 0, 8);
    for (size_t i = 0; i < 9; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl
         << "pivot index is :" << partitionindex;
}
/// nlogn
// worst if the array are sort it will be O(n^2)