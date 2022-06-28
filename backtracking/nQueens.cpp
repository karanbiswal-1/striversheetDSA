#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> cur, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        if (cur[i][col] == 1)
        {
            return false;
        }
    }
    int i = row - 1;
    int j = col - 1;
    while (i >= 0 && j >= 0)
    {
        if (cur[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }
    i = row - 1;
    j = col + 1;
    while (i >= 0 && col < n)
    {
        if (cur[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void fill(int row, int q, int n, vector<vector<int>> &cur, vector<vector<int>> &ans)
{
    if (row == n && q == n)
    {
        for (auto arr : cur)
        {
            vector<int> temp;
            for (auto it : arr)
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (check(cur, row, col))
        {
            cur[row][col] = 1;
            fill(row + 1, q + 1, n, cur, ans);
            cur[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    // Write your code here.
    vector<vector<int>> ans(n, vector<int>(n, 0));
    vector<vector<int>> cur(n, vector<int>(n, 0));
    fill(0, 0, n, cur, ans);
    return ans;
}
