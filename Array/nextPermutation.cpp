#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int k;
    for (k = n - 2; k >= 0; k--)
    {
        if (permutation[k] < permutation[k + 1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(permutation.begin(), permutation.end());
    }
    else
    {
        for (int i = n - 1; i > k; i--)
        {
            if (permutation[i] > permutation[k])
            {
                swap(permutation[i], permutation[k]);
                break;
            }
        }
        reverse(permutation.begin() + k + 1, permutation.end());
    }
    return permutation;
}

int main()
{
    vector<int> perm{1, 2, 4, 3};
    int n = 4;
    perm = nextPermutation(perm, n);
    for (int i : perm)
    {
        cout << i << " ";
    }
    return 0;
}