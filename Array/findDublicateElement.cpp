#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n)
{
    int res;
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i])] < 0)
        {
            res = abs(arr[i]);
        }
        else
        {
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        }
    }
    return res;
}
