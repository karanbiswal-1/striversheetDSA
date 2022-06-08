#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr)
{
    int n = arr.size();
    vector<int> temp(n);
    unordered_map<int, int> mp;
    int res = 0;

    temp[0] = arr[0];
    mp[0] = -1;
    for (int i = 1; i < n; i++)
    {
        temp[i] += arr[i] + temp[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        if (mp[temp[i]])
        {
            res = max(res, i - mp[temp[i]]);
        }
        else
        {
            mp[temp[i]] = i;
        }
    }
    return res;
}

int main()
{
    vector<int> arr{1, -1, 2, -2};
    cout << LongestSubsetWithZeroSum(arr);
}