#include <bits/stdc++.h>
using namespace std;

double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    int n = items.size();
    sort(items.begin(), items.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second / a.first > b.second / b.first; });
    double maxVal = 0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].first <= w)
        {
            maxVal += items[i].second;
            w -= items[i].first;
        }
        else
        {
            maxVal += w * (items[i].second / items[i].first);
            break;
        }
    }
    return maxVal;
}