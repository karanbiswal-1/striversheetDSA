#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

bool detectCycle(Node *head)
{
    //	Write your code here
    Node *slow = head;
    Node *fast = head;
    int i = 0;

    while (fast && fast->next)
    {
        if (slow == fast && i++ > 0)
        {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}