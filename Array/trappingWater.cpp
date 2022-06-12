#include <bits/stdc++.h>
using namespace std;

long getTrappedWater(long *arr, int n)
{
    // Write your code here.
    long lmax = 0;
    long rmax = 0;
    int i = 0;
    int j = n - 1;
    long sum = 0;
    while (i < j)
    {
        lmax = max(lmax, arr[i]);
        rmax = max(rmax, arr[j]);

        if (lmax < rmax)
        {
            sum += lmax - arr[i];
            i++;
        }
        else
        {
            sum += rmax - arr[j];
            j--;
        }
    }
    return sum;
}