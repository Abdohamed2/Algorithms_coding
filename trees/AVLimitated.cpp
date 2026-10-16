#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Node
{
    T data;
    Node<T> *right = NULL;
    Node<T> *left = NULL;
    int height = 1;
};
template <typename T>
class AVL
{
private:
    Node<T> *root;
    int height(Node<T> *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }
    int balanceFactor(Node<T> *node)
    {
        if (node == nullptr)
        {

            return 0;
        }
        return height(node->left) - height(node->right);
    }
    Node<T> *rightrotaion(Node<T> *y)
    {
        Node<T> *x = y->left;
        Node<T> *xright = x->right;
        x->right = y;
        y->left = xright;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return x;
    }
    Node<T> *leftrotat(Node<T> *y)
    {
        Node<T> *x = y->right;
        Node<T> *xleft = x->left;
        x->left = y;
        y->right = xleft;
        x->height = max(height(x->right), height(x->left)) + 1;
        y->height = max(height(y->right), height(y->left)) + 1;
        return x;
    }
    Node<T> *insert(Node<T> *node, T key)
    {
        if (node == nullptr)
        {
            Node<T> *newnode = new Node<T>;
            newnode->data = key;
            node = newnode;
        }

        else if (node->data < key)
        {
            insert(node->right, key);
        }
        else if (node->data > key)
        {
            insert(node->left, key);
        }
        else
            return node;

        node->height = max(height(node->right), height(node->left)) + 1;
        int balance = balanceFactor(node);
        // left heavy
        if (balance > 1)
        {
            // LL
            if (balanceFactor(node->left) >= 0)
            {
                return rightrotaion(node);
            }
            // LR
            else
            {
                node->left = leftrotat(node->left);
                return rightrotaion(node);
            }
        }
        if (balance < -1)
        {
            // RR
            if (balanceFactor(node->right) <= 0)
            {
                return leftrotat(node);
            }
            // RL
            else
            {
                node->right = rightrotaion(node->right);
                return leftrotat(node);
            }
        }
        return node;
    }
    Node<T> *minValueNode(AVLNode<T> *node)
    {
        Node<T> *current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }
    Node<T> *Delete(Node<T> *root, T key)
    {

        // Perform standard BST delete
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else
        {
            // Node with only one child or no child
            if ((root->left == nullptr) || (root->right == nullptr))
            {
                Node<T> *temp = root->left ? root->left : root->right;

                if (temp == nullptr)
                {
                    delete root;
                    return nullptr;
                }
                else
                {
                    Node<T> *old = root;
                    root = temp;
                    delete old;
                }
            }

            else
            {

                Node<T> *temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
    }
};
int main()
{
}