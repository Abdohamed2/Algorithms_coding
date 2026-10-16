#include <bits/stdc++.h>
using namespace std;
template <typename T>
class node
{
public:
    T data;
    node<T> *next;
};
template <typename T>
class linkedlist
{
public:
    node<T> *head = NULL;

    bool isempty()
    {
        return (head == NULL);
    }
    void insertfirst(T value)
    {
        node<T> *newnode = new node<T>;
        newnode->data = value;
        if (isempty())
        {

            newnode->next = NULL;
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    void display()
    {
        node<T> *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }

    int count()
    {
        node<T> *current = head;
        int counter = 0;
        while (current != NULL)
        {
            counter++;
            current = current->next;
        }

        return counter;
    }
    bool isfound(T c)
    {
        bool found = false;
        node<T> *current = head;
        while (current != NULL)
        {
            if (current->data == c)
            {
                found = true;
            }
            current = current->next;
        }
        return found;
    }
    void insertbeatindex0based(T c, int index)
    {
        node<T> *current = head;
        node<T> *newnode = new node<T>;
        int counter = 0;
        if (c < 0)
        {
            return;
        }
        if (c = 0)
        {
            insertitem(c);
        }
        while (current != NULL && counter < index - 1)
        {
            current = current->next;
            counter++;
        }
        if (current == NULL)
        {
            cout << "out of bounds" << endl;
            return;
        }
        newnode->data = c;
        newnode->next = current->next; // if the next of current is node then it will be for newnode or if it is a null it will be null
        current->next = newnode;
    }
    void deletitem(T item)
    {
        if (head == NULL)
        {
            cout << "empty linkedlist";
            return;
        }

        // ✅ delete all matching heads first
        while (head != NULL && head->data == item)
        {
            node<T> *delptr = head;
            head = head->next;
            delete delptr;
        }

        node<T> *current = head;

        // ✅ safe traversal
        while (current != NULL && current->next != NULL)
        {
            if (current->next->data == item)
            {
                node<T> *delptr = current->next;
                current->next = current->next->next;
                delete delptr;
            }
            else
            {
                current = current->next;
            }
        }
    }
    void revoke(T item)
    {
        if (head == NULL)
        {
            cout << "empty linkedlist";
        }
        while (head != NULL && head->data == item)
        {
            node<T> *deleptr = head;
            head = head->next;
            delete deleptr;
        }
        node<T> *current = head;
        while (current != NULL && current->next != NULL)
        {
            if (current->next->data == item)
            {
                node<T> *deltptr = current->next;
                current->next = current->next->next;
                delete deltptr;
            }
            current = current->next;
        }
    }
};
int main()
{

    linkedlist<int> list;
    list.insertfirst(5);
    list.insertfirst(5);
    list.insertfirst(70);
    // list.insertbeatindex0based(70, 10);
    //  list.display();
    list.revoke(70);
    list.display();
}
