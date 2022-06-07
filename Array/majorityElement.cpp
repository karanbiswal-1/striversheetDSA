#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n)
{
    // Write your code here.
    int count = 0;
    int major = 0;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            major = arr[i];
        }
        if (arr[i] == major)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == major)
        {
            count++;
        }
    }
    if (count <= n / 2)
    {
        return -1;
    }
    return major;
}
int main()
{
    int arr[] = {5, 2, 0, 0};
    cout << findMajorityElement(arr, 4);
}