#include <bits/stdc++.h>
using namespace std;
template <typename T>
class stacknode
{
public:
    T data;
    stacknode *next = NULL;
};
template <typename T>
class sack
{
public:
    stacknode<T> *head = NULL;

    void insert(T dat)
    {
        stacknode<T> *newnode = new stacknode<T>;
        newnode->data = dat;
        if (head == NULL)
        {
            head = newnode;
            head->next = NULL;
        }
        else
        {

            newnode->data = dat;
            newnode->next = head;
            head = newnode;
        }
    }
    void traverse()

    {
        stacknode<T> *current = head;
        while (current != NULL)
        {
            cout << current->data << "=>";
            current = current->next;
        }
        cout << "NULL";
    }
};

int main()
{
    sack<int> instance;
    instance.insert(5);
    instance.insert(100);
    instance.insert(10000);
    instance.traverse();
}