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

Node *solve(Node *head, int n, int b[], int i)
{

    if (i >= n)
    {
        return head;
    }
    if (b[i] == 0)
    {
        return solve(head, n, b, ++i);
    }
    Node *dummy = NULL;
    Node *first = head;
    for (int j = 0; j < b[i] && head; j++)
    {
        Node *temp = head->next;
        head->next = dummy;
        dummy = head;
        head = temp;
    }
    first->next = solve(head, n, b, ++i);
    return dummy;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    // Write your code here.
    return solve(head, n, b, 0);
}