#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<vector<int>> pascalTrngle(int n)
    {
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i].resize(i + 1);
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    ans[i][j] = 1;
                }
                else
                {
                    ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
                }
            }
        }
        return ans;
    }

    void printVector(vector<vector<int>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    solution s;
    int n = 5;
    vector<vector<int>> ans = s.pascalTrngle(n);
    s.printVector(ans);
    return 0;
}