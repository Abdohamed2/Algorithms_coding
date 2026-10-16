#include <bits/stdc++.h>
using namespace std;
void merge(int arr_a[], int size_a, int arr_b[], int size_b, int arr_c[])
{
    int index_A = 0;
    int index_B = 0;
    int index_c = 0;
    while (index_A < size_a && index_B < size_b)
    {
        if (arr_a[index_A] < arr_b[index_B])
        {
            arr_c[index_c++] = arr_a[index_A++];
        }
        else
            arr_c[index_c++] = arr_b[index_B++];
    }
    while (index_A < size_a)
    {
        arr_c[index_c++] = arr_a[index_A++];
    }
    while (index_B < size_b)
    {
        arr_c[index_c++] = arr_b[index_B++];
    }
}
void mergesort(int array[], int size_arr)
{
    if (size_arr > 1)
    {
        int sizefirstarray = size_arr / 2;
        int firstarray[sizefirstarray];
        for (size_t i = 0; i < sizefirstarray; i++)
        {
            firstarray[i] = array[i];
        }
        mergesort(firstarray, sizefirstarray);
        int sizesecondarray = size_arr - sizefirstarray;
        int secondarray[sizesecondarray];
        int secendarray1stindex = sizefirstarray;
        for (size_t i = 0; i < sizesecondarray; i++)
        {
            secondarray[i] = array[secendarray1stindex++];
        }
        mergesort(secondarray, sizesecondarray);
        merge(firstarray, sizefirstarray, secondarray, sizesecondarray, array);
    }
}

int main()
{
    int array[6] = {6, 5, 4, 3, 2, 1};
    mergesort(array, 6);
    for (int i : array)
    {
        cout << i << " ";
    }
}