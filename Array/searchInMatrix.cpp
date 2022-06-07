#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool findTargetInMatrix(vector<vector<int>> &mat, int m, int n, int target)
{
    int l = 0;
    if (mat.size() == 0)
    {
        return false;
    }
    int h = (mat.size() * mat[0].size()) - 1;
    int temp = mat[0].size();

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (mat[mid / temp][mid % temp] == target)
        {
            return true;
        }
        else if (mat[mid / temp][mid % temp] > target)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return false;
}