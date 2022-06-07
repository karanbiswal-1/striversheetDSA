#include <bits/stdc++.h>
using namespace std;

long long merge(long long *arr, long long temp[], int l, int mid, int h)
{
    long long res = 0;
    int k = l;
    int i = l;
    int j = mid;

    while (i <= mid - 1 && j <= h)
    {
        if (*(arr + i) < *(arr + j))
        {
            temp[k++] = *(arr + i);
            i++;
        }
        else
        {
            temp[k++] = *(arr + j);
            j++;
            res += (mid - i);
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = *(arr + i);
        i++;
    }
    while (j <= h)
    {
        temp[k++] = *(arr + j);
        j++;
    }
    for (int i = l; i <= h; i++)
    {
        *(arr + i) = temp[i];
    }

    return res;
}

long long mergeSort(long long *arr, long long temp[], int l, int h)
{
    int mid;
    long long count = 0;

    if (l < h)
    {
        mid = (l + h) / 2;
        count += mergeSort(arr, temp, l, mid);
        count += mergeSort(arr, temp, mid + 1, h);
        count += merge(arr, temp, l, mid + 1, h);
    }
    return count;
}

long long getInversions(long long *arr, int n)
{
    long long temp[n];
    return mergeSort(arr, temp, 0, n - 1);
}