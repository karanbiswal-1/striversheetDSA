#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    int data;
    LinkedListNode<int> *next;
    LinkedListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    // Write your code here
    LinkedListNode<int> *dummy = NULL;
    while (head)
    {
        LinkedListNode<int> *next = head->next;
        head->next = dummy;
        dummy = head;
        head = next;
    }
    return dummy;
}