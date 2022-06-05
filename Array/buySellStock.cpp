#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices)
{
    int min = INT_MAX;
    int max = INT_MIN;
    int minI = 0;
    int maxi = 0;
    int maxProfit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
            minI = i;
        }
        if (prices[i] > max || prices[i] > min)
        {
            max = prices[i];
            maxi = i;
        }
        if (maxi > minI && ((max - min) > maxProfit))
        {
            maxProfit = max - min;
        }
    }
    return maxProfit;
}

int main()
{
    vector<int> p{98, 101, 66, 72};
    cout << maximumProfit(p);
}