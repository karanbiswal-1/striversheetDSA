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

LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    LinkedListNode<int> *temp = NULL;
    while (head)
    {
        LinkedListNode<int> *next = head->next;
        head->next = temp;
        temp = head;
        head = head->next;
    }
    return temp;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    // Write your code here.
    if (!head || !head->next)
    {
        return true;
    }

    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    while (slow)
    {
        if (head->data != slow->data)
        {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}

int main()
{
    LinkedListNode<int> *head = new LinkedListNode(-1);
    cout << isPalindrome(head);
}