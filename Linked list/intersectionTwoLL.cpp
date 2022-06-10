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

int findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    unordered_map<int, int> mp;
    while (firstHead)
    {
        mp[firstHead->data]++;
        firstHead = firstHead->next;
    }
    while (secondHead)
    {
        if (mp[secondHead->data])
        {
            return secondHead->data;
        }
        secondHead = secondHead->next;
    }
    return -1;
}