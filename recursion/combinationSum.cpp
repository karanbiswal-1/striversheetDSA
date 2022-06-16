#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &arr, vector<int> curr, vector<vector<int>> &ans, int ind, int n, int k)
{
    if (ind == n)
    {
        if (k == 0)
        {
            ans.push_back(curr);
            return;
        }
    }
    curr.push_back(arr[ind]);
    helper(arr, curr, ans, ind + 1, n, k - arr[ind]);
    curr.pop_back();
    helper(arr, curr, ans, ind + 1, n, k);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> curr;
    helper(arr, curr, ans, n, 0, k);
    return ans;
}