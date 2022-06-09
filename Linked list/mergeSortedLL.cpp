#include <bits/stdc++.h>

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // Write your code here.
    Node<int> *head;
    Node<int> *curr = NULL;
    head = curr;
    while (first && second)
    {
        if (first->data >= second->data)
        {
            curr->next = first;
            first = first->next;
        }
        else
        {
            curr->next = second;
            second = second->next;
        }
        curr = curr->next;
    }
    while (first)
    {
        curr->next = first;
        first = first->next;
        curr = curr->next;
    }
    while (second)
    {
        curr->next = second;
        second = second->next;
        curr = curr->next;
    }
    return head->next;
}