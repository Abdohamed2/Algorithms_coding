#include <bits/stdc++.h>
using namespace std;
template <class T>
class selectionsortAlgorithm
{
public:
    void selectionsort(T data[], int a)
    {
        for (size_t i = 0; i < a - 1; i++)
        {
            T least = i;
            for (size_t j = i + 1; j < a; j++)
            {
                if (data[least] > data[j])
                {
                    least = j;
                }
            }
            swap(data[least], data[i]);
        }

        for (size_t i = 0; i < a; i++)
        {
            cout << data[i] << " ";
        }
    }
    void selectionsort_2(T data[], int n)
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

        for (size_t i = 0; i < n; i++)
        {
            cout << data[i] << " ";
        }
    }
};

int main()
{
    int n[11] = {2, 10, 9, 5, 4, 6, 7, 8, 0, 1, 3};
    selectionsortAlgorithm<int> hey;
    hey.selectionsort(n, 11);
    cout << endl;
    hey.selectionsort_2(n, 11);
}

// every_case
// o(n^2) comparison

// o(n) swap
// o(n) moves
