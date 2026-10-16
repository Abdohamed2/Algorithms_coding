#include <bits/stdc++.h>
using namespace std;
template <typename T>
class node
{
public:
    T data;

    node<T> *left;
    node<T> *right;
    node()
    {
        left = right = NULL;
    }
};
template <typename T>
class BST
{
public:
    node<T> *root = NULL;
    node<T> *insert(node<T> *r, T data)
    {
        if (r == NULL)
        {
            node<T> *newnode = new node<T>;
            newnode->data = data;
            r = newnode;
        }
        else if (r->data > data)
        {
            r->left = insert(r->left, data);
        }
        else
            r->right = insert(r->right, data);
        return r;
    }

    void insert(T data)
    {
        root = insert(root, data);
    }
    void preorder(node<T> *r)
    {
        if (r == NULL)
            return;

        cout << r->data << '\t';
        preorder(r->left);
        preorder(r->right);
    }
    void BFS(node<T> *r)
    {
        queue<node<T> *> q;
        q.push(root);
        while (!q.empty())
        {

            node<T> *current = q.front();
            q.pop();
            cout << current->data;
            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);

            cout << '\t';
        }
    }
    void inorder(node<T> *r)
    {
        if (r == NULL)
            return;

        inorder(r->left);
        cout << r->data << '\t';
        inorder(r->right);
    }
    node<T> *search(node<T> *r, T item)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if (r->data == item)
        {
            return r;
        }
        else if (item < r->data)
        {
            return search(r->left, item);
        }
        else
            return search(r->right, item);
    }
    bool search(T item)
    {
        node<T> *check = search(root, item);
        if (check == NULL)
            return false;
        else
            return true;
    }
    node<T> *findmin(node<T> *r)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if (r->left == NULL)
            return r;
        else
            return findmin(r->left);
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
    node<T> *Delete(node<T> *current, T value)
    {
        if (current == NULL)
        {
            return NULL;
        }
        if (value > current->data)
        {
            current->right = Delete(current->right, value);
        }
        else if (value < current->data)
        {
            current->left = Delete(current->left, value);
        }
        else
        {
            if (current->left == NULL && current->right == NULL)
            {
                current = NULL;
            }
            else if (current->right == NULL && current->left != NULL)
            {
                node<T> *temp = current->left;
                delete current;
                return temp;
            }
            else if (current->left == NULL && current->right != NULL)
            {
                node<T> *temp = current->right;
                delete current;
                return temp;
            }
            else
            {
                node<T> *max = findmax(current->left);
                current->data = max->data;
                current->left = Delete(current->left, max->data);
            }
        }
        return current;
    }
};
int main()
{
    BST<int> instance;
    instance.insert(50);
    instance.insert(10);
    instance.insert(20);
    instance.insert(30);
    instance.insert(12);
    instance.insert(56);
    instance.Delete(instance.root, 10);
    instance.preorder(instance.root);
    cout << endl
         << endl;
    instance.BFS(instance.root);
}

//  instance.preorder(instance.root);
// instance.search(10);
//   node<int> *n;
//  n = instance.findmax(instance.root);

// cout << n->data;