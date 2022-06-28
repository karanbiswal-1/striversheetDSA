#include <bits/stdc++.h>
using namespace std;

bool isPossible(int node, vector<vector<int>> mat, vector<int> col, int n, int m, int c)
{
    for (int i = 0; i < n; i++)
    {
        if (mat[node][i] == 1 && col[i] == c)
        {
            return false;
        }
    }
    return true;
}

string solve(int node, vector<vector<int>> mat, vector<int> col, int n, int m)
{
    if (node == n)
    {
        return "YES";
    }
    for (int i = 1; i <= m; i++)
    {
        if (isPossible(node, mat, col, n, m, i))
        {
            col[node] = i;
            if (solve(node + 1, mat, col, n, m) == "YES")
            {
                return "YES";
            }
            else
            {
                col[node] = 0;
            }
        }
    }
    return "NO";
}

string graphColoring(vector<vector<int>> &mat, int m)
{
    // Write your code here
    int n = mat.size();
    vector<int> col(n, 0);
    return solve(0, mat, col, n, m);
}