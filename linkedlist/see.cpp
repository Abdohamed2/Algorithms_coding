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
    void insert(T item)
    {

        if (isempty())
        {
            node<T> *newnode = new node<T>;
            newnode->data = item;
            head = newnode;
            newnode->next = NULL; // this line is crucial to tell this is none thing after this node
        }
        else
        {

            node<T> *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            node<T> *newnode = new node<T>;
            newnode->data = item;
            current->next = newnode;
            newnode->next = NULL;
        }
    }
    void insertatposzerobased(T item, int pos)
    {
        int counter = 0;
        node<T> newnode = new node<T>;
        newnode->data = item;
        if (pos == 0)
        {
            if (head == NULL)
            {
                cout << "empty linkedlist";
            }
            else
            {
                newnode->next;
            }
        }
    }
    void traverse()
    {
        node<T> *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
    void deletenode(T item)
    {
        if (head == NULL)
        {
            cout << "empty linked_list";
        }
        if (head->data == item)
        {
            node<T> *delptr = head;
            head = head->next;
            delete delptr;
        }
        else
        {
            node<T> *current = head;
            while (current->next != NULL)
            {
                , .

                  if (current->next->data == item)
                {
                    node<T> *deleptr = new node<T>;
                    deleptr = current->next;
                    current->next = current->next->next;
                    delete deleptr;
                }
            }
        }
    }
};
int main()

{
    linkedlist<int> link;
    link.insert(5);
    link.insert(7000000);
    link.insert(7000000);
    link.insert(7000000);
    link.insert(7000000);
    link.insert(7000000);
    link.insert(7000000);
    link.insert(7000000);
    link.insert(7000000);
    link.insert(7000000);
    link.insert(5);
    link.insert(5);
    link.insert(5);
    link.insert(5);
    link.insert(5);
    link.insert(5);
    link.insert(5);
    link.insert(5);
    link.insert(5);
    link.insert(5);
    link.insert(5);
    link.insert(5);
    link.insert(5);
    link.insert(5);
    link.traverse();
    cout << endl;
    link.deletenode(7000000);
    link.traverse();
}
