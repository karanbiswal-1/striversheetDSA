#include <bits/stdc++.h>
using namespace std;

int countHelper(vector<int> arr, int n, int m, int k)
{
    int s = 0;
    int e = m - 1;
    int mid;

    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] <= k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return s;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int k = (n * m / 2) + 1;

    int s = 0;
    int e = 100006;
    int mid;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += countHelper(matrix[i], n, m, mid);
        }
        if (count <= k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return s;
}