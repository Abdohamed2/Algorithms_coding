#include <bits/stdc++.h>
using namespace std;
template <class T>
void bubblesort1(T data[], int n)
{
    for (size_t i = 0; i < n - 1; i++) // you see this' | ' to define for you where the loop stop in every iteration
    {
        for (size_t j = 0; j < n - 1 - i; j++)
        {
            if (data[j] > data[j + 1])

            {
                swap(data[j], data[j + 1]); // 7 4 5 6 2 1
                                            //         |
                                            // 4 5 6 2 1 7
                                            //       |
                                            // 4 5 2 1 6 7
                                            //     |
                                            // 4 2 1 5 6 7
                                            //   |
                                            // 2 1 4 5 6 7
                                            // |
                                            // 1 2 4 5 6 7
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
}
template <class T>
void bubblesort2(T data[], int n)

{
    int c = 0;
    bool flag = true;
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = n - 1; j > i; j--)
        {
            c++;
            if (data[j] >
                data[j - 1])

            {
                swap(data[j], data[j - 1]);
                flag = false;
            }
        }

        if (flag == true)
        {
            cout << c;
            break;
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
    int n[11] = {2, 10, 9, 5, 4, 6, 7, 8, 0, 1, 3};
    bubblesort1(n, 11);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    int l[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubblesort2(l, 11);
}