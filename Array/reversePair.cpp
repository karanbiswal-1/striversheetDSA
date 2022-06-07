#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int n, int l, int mid, int h)
{
    int ans = 0;
    int j = mid + 1;
    for (int i = l; i <= mid; i++)
    {
        while (j <= h && arr[i] > 2 * arr[j])
        {
            j++;
        }
        ans += j - (mid + 1);
    }
    vector<int> temp;
    int i = l;
    j = mid + 1;
    while (i <= mid && j <= h)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= h)
    {
        temp.push_back(arr[j++]);
    }
    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[i - l];
    }
    return ans;
}

int mergeSort(vector<int> &arr, int n, int l, int h)
{
    int res = 0;
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        res = mergeSort(arr, n, l, mid);
        res += mergeSort(arr, n, mid + 1, h);
        res += merge(arr, n, l, mid, h);
    }
    return res;
}

int reversePairs(vector<int> &arr, int n)
{
    // Write your code here.
    int l = 0;
    int h = n - 1;
    return mergeSort(arr, n, l, h);
}
