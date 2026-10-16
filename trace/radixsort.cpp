#include <bits/stdc++.h>
using namespace std;
void countsort(int arr[], int n, int pos)
{
    int count[10] = {0};
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        ++count[(arr[i] / pos) % 10];
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        arr2[--count[(arr[i] / pos) % 10]] = arr[i];
    }
    for (int i = 0; i < n; i++)
        arr[i] = arr2[i];
}
void radixsort(int arr[], int n)
{

    int maxVal = *std::max_element(arr, arr + n);
    for (int pos = 1; maxVal / pos > 0; pos *= 10)
    {
        countsort(arr, n, pos);
    }
}
int main()
{
    int arr[] = {320, 250, 44, 10, 2, 35, 9};
    radixsort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}