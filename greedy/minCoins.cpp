#include <bits/stdc++.h>
using namespace std;

int findMinimumCoins(int amount)
{
    // Write your code here
    vector<int> dom{1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = dom.size();
    int minCoins = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (dom[i] <= amount)
        {
            amount -= dom[i];
            minCoins++;
            if (amount == 0)
            {
                break;
            }
        }
    }
    return minCoins;
}
