#include <iostream>
using namespace std;

// Global counters for comparisons and swaps
int comparisons = 0;
int swaps = 0;

// Function Prototypes
void bubbleSortAscending(int arr[], int start, int end);
void selectionSortDescending(int arr[], int start, int end);
int linearSearch(int arr[], int n, int target);
void printArray(int arr[], int n);
void runTestCase(int arr[], int n, int target);

int main()
{

    cout << "Test Case 1: Target at bitonic point" << endl;
    int arr1[] = {5, 1, 9, 12, 7, 3, 2};
    runTestCase(arr1, 7, 12);

    cout << "Test Case 2: Target in left half" << endl;
    int arr2[] = {8, 4, 1, 10, 9, 6, 3};
    runTestCase(arr2, 7, 4);

    cout << "Test Case 3: Target in right half" << endl;
    int arr3[] = {2, 7, 11, 15, 10, 6, 1};
    runTestCase(arr3, 7, 6);

    cout << "Test Case 4: Target not present" << endl;
    int arr4[] = {3, 9, 1, 12, 8, 4, 2};
    runTestCase(arr4, 7, 100);

    cout << "Test Case 5: Array with duplicates" << endl;
    int arr5[] = {5, 1, 5, 9, 9, 3, 3};
    runTestCase(arr5, 7, 5);

    return 0;
}

// sorts left half in ascending order using bubble sort
void bubbleSortAscending(int arr[], int start, int end)
{
    for (int pass = 0; pass < end - start; pass++)
    {
        for (int j = start; j < end - pass; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

// sorts right half in descending order using selection sort
void selectionSortDescending(int arr[], int start, int end)
{
    for (int i = start; i < end; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j <= end; j++)
        {
            comparisons++;
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            swap(arr[i], arr[maxIndex]);
            swaps++;
        }
    }
}

// searches for target and returns it
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// prints the array elements
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// runs one test case it makes bitonic array, searches target, prints results
void runTestCase(int arr[], int n, int target)
{
    comparisons = 0;
    swaps = 0;

    int mid = n / 2;

    bubbleSortAscending(arr, 0, mid - 1);
    selectionSortDescending(arr, mid, n - 1);

    cout << "Bitonic Array: ";
    printArray(arr, n);

    int index = linearSearch(arr, n, target);

    if (index != -1)
    {
        cout << "Target " << target << " found at index " << index << endl;
    }
    else
    {
        cout << "Target " << target << " not found" << endl;
    }

    cout << "Total comparisons during sorting: " << comparisons << endl;
    cout << "Total swaps during sorting: " << swaps << endl;
    cout << "----------------------------------------" << endl;
}