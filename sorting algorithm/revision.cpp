#include <bits/stdc++.h>
using namespace std;
template <typename T>
void selectionsorting(T data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (data[i] > data[j])
            {
                swap(data[i], data[j]);
            }
        }
    }
}
int main()
{
    int arr[] = {10, 2, 23, 5, 68, 9};
    selectionsorting(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}