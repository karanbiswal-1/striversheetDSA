#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); i++)
    {
        if (ans.empty() || ans.back()[1] < intervals[i][0])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}