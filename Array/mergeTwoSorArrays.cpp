#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // Write your code here
    for (int i = 0; i < m; i++)
    {
        if (arr1[i] > arr2[0])
        {
            swap(arr1[i], arr2[0]);
        }
        int first = arr2[0];
        int j;
        for (j = 1; j < n && arr2[j] < first; j++)
        {
            arr2[j - 1] = arr2[j];
        }
        arr2[j - 1] = first;
    }
    for (int i : arr2)
    {
        arr1.push_back(i);
    }
    return arr1;
}

int main()
{
    vector<int> a{1, 3, 5, 7};
    vector<int> b{2, 4, 6};
    vector<int> ans = ninjaAndSortedArrays(a, b, 4, 3);
    for (int i : ans)
    {
        cout << i << " ";
    }
}