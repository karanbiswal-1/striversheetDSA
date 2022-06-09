#include <bits/stdc++.h>

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void deleteNode(LinkedListNode<int> *node)
{
    // Write your code here.
    LinkedListNode<int> *temp;
    while (node->next)
    {
        if (!node->next->next)
        {
            temp = node;
        }
        node->data = node->next->data;
        node = node->next;
    }
    temp->next = NULL;
}