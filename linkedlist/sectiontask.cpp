#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> brackets;
    string b;
    cin >> b;
    bool flag = false;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] != '{' || b[i] != '}')
        {
            flag = true;
        }
        else
            continue;
    }

    for (int i = 0; i < b.size(); i++)
    {

        if (b[i] == ('{'))
        {
            brackets.push(b[i]);
        }
        else if (b[i] == ('}') && !brackets.empty())
        {
            brackets.pop();
        }
        else
            continue;
    }
    bool empty = brackets.empty();
    if (empty && flag == false)
        cout << "balance";
    else if (!empty || flag == true)
        cout << "not balance";
}