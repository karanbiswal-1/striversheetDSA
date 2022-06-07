#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &dp, int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }
    else if (i >= m || j >= n)
    {
        return 0;
    }
    else if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = solve(dp, i + 1, j, m, n) + solve(dp, i, j + 1, m, n);
    }
}

int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int res = solve(dp, 0, 0, m, n);
    return dp[0][0];
}