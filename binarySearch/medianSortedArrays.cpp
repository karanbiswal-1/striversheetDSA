#include <bits/stdc++.h>
using namespace std;

double solve(vector<int> a, vector<int> b, int m, int n)
{
    if (m < n)
    {
        return solve(b, a, n, m);
    }
    int l = 0;
    int h = m - 1;
    int midpos = (m + n + 1) / 2;
    while (l <= h)
    {
        int mid1 = l + (h - l) / 2;
        int mid2 = midpos - mid1;
        int l1 = mid1 == 0 ? INT_MIN : a[mid1 - 1];
        int l2 = mid2 == 0 ? INT_MIN : b[mid2 - 1];
        int r1 = mid1 == m ? INT_MAX : a[mid1];
        int r2 = mid2 == n ? INT_MAX : b[mid2];

        if (l1 <= r2 && l2 <= r1)
        {
            if (m + n % 2 == 0)
            {
                return (double)(max(l1, l2) + min(r1, r2)) / 2;
            }
            else
            {
                return (double)max(r1, r2);
            }
        }
        else if (l1 > r2)
        {
            h = mid1 - 1;
        }
        else
        {
            l = mid1 + 1;
        }
    }
    return -1;
}

double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    int m = a.size();
    int n = b.size();
    return solve(a, b, m, n);
}
