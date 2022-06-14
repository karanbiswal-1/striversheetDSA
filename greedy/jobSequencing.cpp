#include <bits/stdc++.h>
using namespace std;

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b)
         { return a[1] > b[1]; });
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }
    vector<int> slot(maxDeadline + 1, -1);
    int maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i][0]; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                maxProfit += jobs[i][1];
                break;
            }
        }
    }
    return maxProfit;
}