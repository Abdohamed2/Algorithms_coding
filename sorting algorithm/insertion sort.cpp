#include <bits/stdc++.h>
using namespace std;
template <class T>
void insertionsort(T data[], int n)
{
    for (int i = 1; i < n; i++)
    {

        T temp = data[i];
        for (int j = i; j > 0 && temp < data[j - 1]; j--)
        {
            data[j] = data[j - 1];
            data[j - 1] = temp;
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
}
void insertionsort2(int data[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = data[i];
        int j = i;
        while (j > 0 && data[j - 1] > temp)
        {
            data[j] = data[j - 1];
            data[j - 1] = temp;
            j--;
        }
        for (size_t i = 0; i < n; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n[] = {2, 10, 9, 5, 4, 6, 7, 8, 0, 1, 3};
    // 2 9 10 5 4 6 7 8 0 1 3
    int c[4] = {8, 5, 3, 2};
    insertionsort(c, 4);
    cout << endl;

    insertionsort2(n, 11);
}