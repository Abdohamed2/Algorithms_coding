#include <bits/stdc++.h>
using namespace std;
int tringularnum(int n)
{
    if (n <= 1)
        return 1;
    else
        return n + tringularnum(n - 1);
}
int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}
void anagrams(string s, int n)
{
}
int main()
{
    cout << tringularnum(4) << endl;
    cout << factorial(5);
}