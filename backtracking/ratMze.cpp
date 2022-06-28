#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

bool solve(int r, int c, vector<vector<int>> &maze, vector<vector<int>> &ans, int n)
{
    if (r < 0 || c < 0 || r >= n || c >= n || maze[r][c] == 0 || ans[r][c] == 1)
    {
        return false;
    }
    if (r == n - 1 && c == n - 1)
    {
        for (vector temp : ans)
        {
            res.push_back(temp);
        }
    }
    ans[r][c] = 1;
    solve(r, c + 1, maze, ans, n);
    solve(r + 1, c, maze, ans, n);
    solve(r, c - 1, maze, ans, n);
    solve(r - 1, c, maze, ans, n);
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    // Write your code here.
    int n = maze.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    solve(0, 0, maze, ans, n);
}