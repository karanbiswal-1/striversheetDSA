#include <bits/stdc++.h>
using namespace std;

int uniqueSubstrings(string input)
{
    // Write your code here
    int res = 1;
    int l = 0;
    int r = 0;
    int len = input.size();
    unordered_map<char, int> mp;

    for (int i = 0; i < len; i++)
    {
        if (mp.find(input[i]) != mp.end())
        {
            l = max(mp[input[i]] + 1, l);
        }
        mp[input[i]] = i;
        res = max(res, i - l + 1);
    }
    return res;
}