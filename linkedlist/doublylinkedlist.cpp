#include <bits/stdc++.h>
using namespace std;
template <typename T>
class node
{
public:
    T data;
    node<T> *next = NULL;
    node<T> *prev = NULL;
};
template <typename T>
class doublylinkelist
{
public:
    node<T> *head = NULL;
    void insert(T item)
    {
        node<T> *newnode = new node<T>;
        newnode->data = item;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            node<T> *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newnode;
            newnode->prev = current;
        }
    }
    void traverse()
    {
        node<T> *current = head;
        while (current != NULL)
        {
            cout << current->data << " => ";
            current = current->next;
        }
        cout << "NULL";
    }
    int counting()
    {
        node<T> *current = head;
        int count = 0;
        while (current != NULL)

        {
            current = current->next;
            count++;
        }
        return count;
    }
    // void deletenode(T item)
    // {
    //     if (head == NULL)
    //     {
    //         cout << " empty";
    //     }
    //     while (head != NULL && head->next != NULL)
    //     {
    //         if (head->data == item)
    //         {
    //             node<T> *delptr = head;
    //             delptr = head;
    //             head = head->next;
    //             //  head->next->prev = NULL;
    //             delete delptr;
    //         }
    //     }

    //     node<T> *current = head;
    //     while (current->next != NULL && current->next->data == item)
    //     {
    //         node<T> *delptr = new node<T>;
    //         delptr = current->next;
    //         current->next = current->next->next;
    //         current->prev = current;
    //         delete delptr;
    //     }
    //     current->next = NULL;
    //

    void deletenode(T item)
    {
        if (head == NULL)
        {
            cout << "empty linkedlist";
        }
        if (head->data == item)
        {
            node<T> *delptr = head;
            head = head->next;
            delete delptr;
        }
        else
        {

            for (int i = 0; i < counting(); i++)
            {
                node<T> *delptr = head;
                node<T> *pre = NULL;
                while (delptr->data != item)
                {
                    pre = delptr;
                    delptr = delptr->next;
                }
                pre->next = delptr->next;
                delete delptr;
            }
        }
    }
};

int main()
{
    doublylinkelist<int> link;

    link.insert(70);
    link.insert(5);
    link.insert(56);
    link.insert(750);
    link.insert(54);
    link.insert(4570);
    link.insert(740);
    link.insert(750);
    link.insert(740);
    link.insert(540);
    link.insert(770);
    link.insert(0);

    link.deletenode(740);
    link.traverse();
    cout << endl
         << link.counting();
}

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
public:
    T data;
    node<T> *next = NULL;
    node<T> *prev = NULL;
};

template <typename T>
class doublylinkelist
{
public:
    node<T> *head = NULL;

    void insert(T item)
    {
        node<T> *newnode = new node<T>;
        newnode->data = item;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            node<T> *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newnode;
            newnode->prev = current;
        }
    }

    void traverse()
    {
        node<T> *current = head;
        while (current != NULL)
        {
            cout << current->data << " => ";
            current = current->next;
        }
        cout << "NULL";
    }

    int counting()
    {
        node<T> *current = head;
        int count = 0;
        while (current != NULL)
        {
            current = current->next;
            count++;
        }
        return count;
    }

    void deletenode(T item)
    {
        if (head == NULL)
        {
            cout << "empty linkedlist";
            return;
        }

        node<T> *current = head;

        while (current != NULL)
        {
            if (current->data == item)
            {
                node<T> *delptr = current;

                // if deleting head
                if (current == head)
                {
                    head = head->next;
                    if (head != NULL)
                        head->prev = NULL;
                    current = head;
                }
                else
                {
                    // fix links
                    if (current->next != NULL)
                        current->next->prev = current->prev;

                    if (current->prev != NULL)
                        current->prev->next = current->next;

                    current = current->next;
                }

                delete delptr;
            }
            else
            {
                current = current->next;
            }
        }
    }
};