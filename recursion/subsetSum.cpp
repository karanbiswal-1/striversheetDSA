#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &num, int sum, int index, vector<int> &ss, int n)
{
    if (index == n)
    {
        ss.push_back(sum);
        return;
    }
    helper(num, sum, index + 1, ss, n);
    helper(num, sum + num[index], index + 1, ss, n);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ss;
    int n = num.size();
    int sum = 0;
    int index = 0;
    helper(num, sum, index, ss, n);
    sort(ss.begin(), ss.end());
    return ss;
}