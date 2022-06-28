#include <bits/stdc++.h>
using namespace std;

bool isValid(int mat[9][9], int r, int c, int k)
{
    for (int i = 0; i < 9; i++)
    {
        if (mat[r][i] == k)
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (mat[i][c] == k)
        {
            return false;
        }
    }
    int si = r - (r % 3);
    int sj = c - (c % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mat[si + i][sj + j] == k)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(int mat[9][9], int i, int j)
{
    if (j == 8)
    {
        return true;
    }
    int ni;
    int nj;
    if (i == 8)
    {
        ni = i + 1;
        nj = 0;
    }
    else
    {
        ni = i;
        nj = j + 1;
    }
    if (mat[i][j] != 0)
    {
        solve(mat, ni, nj);
    }
    else
    {
        for (int k = 1; k <= 9; k++)
        {
            if (isValid(mat, i, j, k))
            {
                mat[i][j] = k;
                if (solve(mat, ni, nj))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isItSudoku(int matrix[9][9])
{
    solve(matrix, 0, 0);
}
