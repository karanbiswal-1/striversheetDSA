#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int m, int n)

{

    // Write your code here

    int r = 0, c = 0;

    int prev, cur;

    while (r < m && c < n)

    {

        if (r + 1 == m || c + 1 == n)

            break;

        prev = mat[r + 1][c];

        for (int i = c; i < n; i++)

        {

            cur = mat[r][i];

            mat[r][i] = prev;

            prev = cur;
        }

        r++;

        for (int i = r; i < m; i++)

        {

            cur = mat[i][n - 1];

            mat[i][n - 1] = prev;

            prev = cur;
        }

        n--;

        if (r < m)

        {

            for (int i = n - 1; i >= c; i--)

            {

                cur = mat[m - 1][i];

                mat[m - 1][i] = prev;

                prev = cur;
            }
        }

        m--;

        if (c < n)

        {

            for (int i = m - 1; i >= r; i--)

            {

                cur = mat[i][c];

                mat[i][c] = prev;

                prev = cur;
            }
        }

        c++;
    }
}