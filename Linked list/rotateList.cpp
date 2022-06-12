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

Node *rotate(Node *head, int k)
{
    // Write your code here.
    Node *temp = head;
    int n = 0;

    while (temp)
    {
        temp = temp->next;
        n++;
    }
    k = n % k;
    k = n - k;
    Node *prev;
    while (temp && k)
    {
        prev = temp;
        temp = temp->next;
        k--;
    }
    prev->next = NULL;
    Node *newHead = temp;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = head;
    return newHead;
}