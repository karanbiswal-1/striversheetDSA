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

Node *firstNode(Node *head)

{

    if (head == NULL || head->next == NULL)
    {

        return NULL;
    }

    Node *slow = head;

    Node *fast = head;

    slow = slow->next;

    fast = fast->next->next;

    while (fast && fast->next)
    {

        if (slow == fast)

            break;

        slow = slow->next;

        fast = fast->next->next;
    }

    if (slow != fast)

        return NULL;

    slow = head;

    while (slow != fast)
    {

        slow = slow->next;

        fast = fast->next;
    }

    return slow;
}