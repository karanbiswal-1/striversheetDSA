#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int xorTill = 0;
    int res = 0;
    map<int, int> mp;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        xorTill = xorTill ^ arr[i];
        if (xorTill == x)
        {
            res++;
        }
        if (mp.find(xorTill ^ x) != mp.end())
        {
            res += mp[xorTill ^ x];
        }
        mp[xorTill]++;
    }
    return res;
}