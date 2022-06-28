#include <bits/stdc++.h>
using namespace std;

int bs(int *arr, int l, int h, int key)
{
    int mid = l + (h - l) / 2;
    while (l <= h)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

int solve(int *arr, int l, int h, int n, int key)
{
    int mid = l + (h - l) / 2;
    while (l <= h)
    {
        if (arr[mid == key])
        {
            return mid;
        }
        else if (arr[mid] > arr[0])
        {
            if (key > arr[mid])
            {
                return bs(arr, mid + 1, h, key);
            }
            else
            {
                h = mid - 1;
            }
        }
        else
        {
            if (key < arr[mid])
            {
                return bs(arr, l, mid - 1, key);
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    return -1;
}

int search(int *arr, int n, int key)
{
    // Write your code here.
    int l = 0;
    int h = n - 1;
    solve(arr, l, h, n, key);
}