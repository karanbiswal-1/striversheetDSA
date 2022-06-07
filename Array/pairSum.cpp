#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int n = arr.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        if (mp[s - arr[i]])
        {
            for (int j = 0; j < mp[s - arr[i]]; j++)
            {
                ans.push_back({s - arr[i], arr[i]});
            }
        }

        mp[arr[i]]++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr{2, -6, 2, 2, 5};
    vector<vector<int>> ans = pairSum(arr, 4);
    for (vector<int> temp : ans)
    {
        cout << temp[0] << " " << temp[1] << endl;
    }
}