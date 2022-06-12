#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; i++)
    {
        int f = i;
        ;
        int s = i + 1;
        int t = n - 1;
        int sum = K - arr[f];
        while (s < t)
        {
            if (arr[s] + arr[t] == sum)
            {
                ans.push_back({arr[f], arr[s], arr[t]});
            }
            else if (arr[s] + arr[t] > sum)
            {
                t--;
            }
            else
            {
                s++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr{10, 5, 5, 5, 2};
    int K = 12;
    int n = arr.size();
    vector<vector<int>> ans = findTriplets(arr, n, K);
    for (vector<int> a : ans)
    {
        for (int i : a)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}