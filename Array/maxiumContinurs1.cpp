#include <bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr, int n, int k)
{
    // Write your code here.
    int x = 0;
    int len = 0;
    int zero = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1 || (arr[i] == 0 && zero < k))
        {
            if (arr[i] == 0)
            {
                zero++;
            }
            len = max(len, i - x + 1);
        }
        else
        {
            while (arr[x] == 1)
            {
                x++;
            }
            x++;
        }
    }
    len = max(len, (n - x));
    return len;
}

int main()
{
    vector<int> arr{1, 0, 0, 1, 1, 0, 1};
    int k = 1;
    int n = arr.size();
    cout << longestSubSeg(arr, n, k);
}
