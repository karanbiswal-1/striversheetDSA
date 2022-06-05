#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n)
{
    int *first = arr;
    int *last = arr + n - 1;
    for (int *i = arr; i <= last;)
    {
        if (*i == 0)
        {
            swap(*i, *first);
            first++;
            i++;
        }
        else if (*i == 2)
        {
            swap(*i, *last);
            last--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int a[] = {1, 0, 2, 1, 2, 0, 1};
    int *arr = a;
    int n = 7;
    sort012(arr, n);
    for (int *i = arr; i < arr + n; ++i)
    {
        cout << *i;
    }
    return 0;
}