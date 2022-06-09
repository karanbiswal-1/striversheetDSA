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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
    Node *ans = new Node(1);
    Node *head = ans;
    int rem = 0;
    while (head1 && head2)
    {
        Node *temp = new Node((head1->data + head2->data + rem) % 10);
        rem = (head1->data + head2->data + rem) / 10;
        ans->next = temp;
        head1 = head1->next;
        head2 = head2->next;
        ans = ans->next;
    }
    while (head1)
    {
        Node *temp = new Node((head1->data + rem) % 10);
        rem = (head1->data + rem) / 10;
        ans->next = temp;
        head1 = head1->next;
        ans = ans->next;
    }
    while (head2)
    {
        Node *temp = new Node((head2->data + rem) % 10);
        rem = (head2->data + rem) / 10;
        ans->next = temp;
        head2 = head2->next;
        ans = ans->next;
    }
    return head->next;
}