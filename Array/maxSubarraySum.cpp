#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long maxTill = 0;
    long long maxSoFar = 0;

    for (int i = 0; i < n; i++)
    {
        maxTill += arr[i];
        if (maxSoFar < maxTill)
        {
            maxSoFar = maxTill;
        }
        if (maxTill < 0)
        {
            maxTill = 0;
        }
    }
    return maxSoFar;
}

int main()
{
    int arr[] = {1, 2, 7, -4, 3, 2};
    int n = 6;
    cout << maxSubarraySum(arr, n);
    return 0;
}