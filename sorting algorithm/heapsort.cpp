#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int root)
{
    int largest = root;
    int l = root * 2 + 1;
    int r = root * 2 + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != root)
    {
        swap(arr[largest], arr[root]);
        // recursively heapify the affected sub_tree
        heapify(arr, n, largest);
    }
}
void heapsort(int arr[], int n, int root)
{
    // we will adjusting the arr acording to the max heap
    // and we will start form n/2-1 and its mean the last non terminal node
    // aranging all subtrees (the root will have the max number)

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        // this loop complexity is nlogn and its mean we will do a n complexity for n elment on the height of tree which is logn
        heapify(arr, n, i);
    }
    // deleting from heap
    for (int i = n - 1; i > 0; i--)
    {
        // this loop complexity nlogn the same as inserting
        swap(arr[0], arr[i]);
        // calling the max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
int main()
{
    int arr[] = {9, 5, 4, 6, 1, 0, 2, 3, 6, 5, 9, 10, 4, 65, 8, 9, 9, 999, 10};
    heapsort(arr, 19, 0);
    for (int i = 0; i < 19; i++)
    {
        cout << arr[i] << " ";
    }
}