#include <bits/stdc++.h>
using namespace std;

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

LinkedListNode<int> *removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    int i = 0;

    while (fast->next)
    {
        if (i >= K)
        {
            fast = fast->next;
            slow = slow->next;
        }
        else
        {
            fast = fast->next;
        }
    }
    slow->next = slow->next->next;
    return head;
}