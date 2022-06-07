#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int x = 0;
    int y = 0;
    int bitsXor = 0;

    for (int i = 0; i < n; i++)
    {
        bitsXor ^= arr[i] ^ (i + 1);
    }
    bitsXor = bitsXor & ~(bitsXor - 1);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] & bitsXor)
        {
            x ^= arr[i];
        }
        else
        {
            y ^= arr[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & bitsXor)
        {
            x ^= i;
        }
        else
        {
            y ^= i;
        }
    }
    for (int i : arr)
    {
        if (i == x)
        {
            return {y, x};
        }
    }
    return {x, y};
}

int main()
{
    vector<int> arr{1, 3, 5, 4, 4};
    pair<int, int> ans = missingAndRepeating(arr, 5);
    cout << ans.first << " " << ans.second;
}