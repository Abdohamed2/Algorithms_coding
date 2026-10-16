#include <bits/stdc++.h>
using namespace std;
void shellsort(int arr[], int n)
{
    int size = n;
    size /= 2;
    while (size > 0) // this loop for type of diffrent size of groups like knuth's sequence interval groups
    {
        for (int i = size; i < n; i++) // this loop for all groups with the same size
        {
            int temp = arr[i];
            int inner = i;
            while (inner - size >= 0 && temp < arr[inner - size])
            {

                arr[inner] = arr[inner - size];
                inner -= size;
            }
            arr[inner] = temp;
        }
        size /= 2;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void sheellsor(int arr[], int k)

{
    int n = k / 2;
    while (n > 0)
    {
        for (int i = n; i < k; i++)

        {
            int temp = arr[i];
            int inner = i;
            while (inner - n >= 0 && temp < arr[inner - n])
            {
                arr[inner] = arr[inner - n];
                inner -= n;
            }
            arr[inner] = temp;
        }

        n /= 2;
    }
    for (size_t i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {6, 8, 9, 7, 1, 2, 0, 5, 4};

    int num = size(arr);
    sheellsor(arr, 9);
}
