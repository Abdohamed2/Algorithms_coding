#include <bits/stdc++.h>
using namespace std;
template <typename T>
class node
{
public:
    T data;
    node<T> *right = NULL;
    node<T> *left = NULL;
};
template <typename T>
class bst
{
public:
    node<T> *root = NULL;
    void insert(node<T> *&r, T data)
    {

        if (r == NULL)
        {
            node<T> *newnode = new node<T>;
            newnode->data = data;

            r = newnode;
        }
        else if (r->data > data)
        {
            insert(r->left, data);
        }
        else
            insert(r->right, data);
    }
    void print(node<T> *r)
    {
        if (r == NULL)
        {
            return;
        }
        cout << r->data;
        print(r->left);
        print(r->right);
    }
    node<T> *findmax(node<T> *r)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if (r->right == NULL)
            return r;
        else
            return findmax(r->right);
    }
    node<T> *Delete(node<T> *&r, T item)
    {
        if (r == NULL)
        {
            return NULL;
        }
        if (item > r->data)
        {
            Delete(r->right, item);
        }
        else if (item < r->data)
        {
            Delete(r->left, item);
        }
        else
        {
            if (r->left == NULL && r->right == NULL)
            {
                delete r;
            }
            else if (r->left == NULL)
            {
                node<T> *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                node<T> *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                node<T> *max = findmax(r->left);
                r->data = max->data;
                r->left = Delete(r->left, max->data);
            }
        }
        return r;
    }
};
int main()
{
    bst<int> instance;
    instance.insert(instance.root, 50);
    instance.print(instance.root);
    instance.insert(instance.root, 500);
    instance.root = instance.Delete(instance.root, 50);
    instance.print(instance.root);
}