#include <bits/stdc++.h>
using namespace std;

int uniqueElement(vector<int> arr, int n)
{
    int ans = 0;
    for (int i : arr)
    {
        ans ^= i;
    }
    return ans;
}
