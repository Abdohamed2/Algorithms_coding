#include <bits/stdc++.h>
using namespace std;
template <typename T>
class node
{
public:
    T data;
    node<T> *next = NULL;
};
template <typename T>
class Stack
{
public:
    node<T> *top = NULL;
    bool isempty()
    {
        return (top == NULL);
    }
    void push(T item)
    {
        node<T> *newnode = new node<T>;
        newnode->data = item;
        if (isempty())
        {
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }
    void display()
    {
        node<T> *current = top;
        while (current != NULL)
        {
            cout << current->data << " => ";
            current = current->next;
        }
        cout << "NULL" << "\n";
    }
    void pop()
    {
        node<T> *deleptr = top;
        top = top->next;
        delete deleptr;
    }
    T returnpop()
    {
        node<T> *deleptr = top;
        T data = top->data;
        top = top->next;
        delete deleptr;
        return data;
    }
    bool isfull()
    {
        node<T> *ptr = new node<T>;
        if (ptr == NULL)
        {
            cout << "heap is full";
        }
    }
};

int main()
{
    Stack<int> link;
    link.push(4);
    link.push(4);
    link.push(4);
    link.push(4);
    link.push(4);
    link.display();
    link.pop();
    link.returnpop();
    link.display();
}