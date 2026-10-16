#include <bits/stdc++.h>
using namespace std;
// this is only to declare with a different way i hope you remmember when you open this file to review before the interview i hope (ارجو وامل ان تدنو مودتها وما اخال لدينا منك تنويل i forgot this things with osama_elwaaez)now i listen to mohamed nour
int main()
{
    struct node
    {
        int data;
        node *next;
    };
    node *head, *newnode;

    head = NULL;
    node *newnode = new node; // simple way
    //////////////////////////////////////////////////
    newnode = (node *)malloc(sizeof(node));
    // different way with casting which here we dynimcally allocte a memory space the same with new keyword
    cin >> newnode->data;
    newnode->next = 0;
    if (head == nullptr)
        head = newnode;
    else
        head->next = newnode;
}