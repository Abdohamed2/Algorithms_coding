#include <bits/stdc++.h>
using namespace std;
void count(int arr[], int maxelment, int size)

{
    int arr1[maxelment + 1] = {0};
    int arr2[size];
    for (size_t i = 0; i < size; i++)
    {
        // arr1[arr[i]++]; there a big different here and a big mistake
        arr1[arr[i]]++;
    }

    for (size_t i = 1; i <= maxelment; i++)
    {

        arr1[i] += arr1[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        arr2[--arr1[arr[i]]] = arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr2[i];
    }
}

int main()
{
    int arr[] = {1, 2, 5, 8, 3, 0, 7, 9, 4, 0};
    count(arr, 9, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}