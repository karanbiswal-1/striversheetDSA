#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &arr, vector<int> &curr, vector<vector<int>> &ans, int ind, int n, int k)
{
    if (k == 0)
    {
        ans.push_back(curr);
        return;
    }

    for (int i = ind; i < n; i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
        {
            continue;
        }
        curr.push_back(arr[i]);
        helper(arr, curr, ans, ind + 1, n, k - arr[i]);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> curr;
    helper(arr, curr, ans, 0, n, target);
    return ans;
}