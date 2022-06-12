#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

Node *merge(Node *h1, Node *h2)
{
    if (!h1)
    {
        return h2;
    }
    if (h2)
    {
        return h1;
    }
    Node *res;
    if (h1 && h2)
    {
        if (h1->data >= h2->data)
        {
            res = h1;
            res->next = merge(h1->child, h2);
        }
        else
        {
            res = h2;
            res->next = merge(h1, h2->child);
        }
    }
    return res;
}

Node *flattenLinkedList(Node *head)
{
    // Write your code here
    if (!head)
    {
        return head;
    }
    return merge(head, flattenLinkedList(head->next));
}
