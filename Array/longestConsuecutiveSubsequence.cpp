#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // Write your code here.
    unordered_map<int, int> mp;
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i] - 1) == mp.end())
        {
            int len = 1;
            int k = arr[i];
            while (mp.find(k + 1) != mp.end())
            {
                len++;
                k++;
            }
            res = max(res, len);
        }
    }
    return res;
}

int main()
{
    vector<int> arr{9, 5, 4, 9, 10, 10, 6};
    cout << lengthOfLongestConsecutiveSequence(arr, 7);
}