#include <bits/stdc++.h>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &finish)
{
    // Write your code here.
    int n = start.size();
    vector<vector<int>> act(n, vector<int>(2));

    for (int i = 0; i < n; i++)
    {
        act[i][0] = finish[i];
        act[i][1] = start[i];
    }
    sort(act.begin(), act.end());
    int maxAct = 1;
    int curr = act[0][0];
    for (int i = 1; i < n; i++)
    {
        if (act[i][1] >= curr)
        {
            maxAct++;
            curr = act[i][0];
        }
    }
    return maxAct;
}

int main()
{
    vector<int> s{1, 6, 2, 4};
    vector<int> e{2, 7, 5, 8};
    cout << maximumActivities(s, e);
}