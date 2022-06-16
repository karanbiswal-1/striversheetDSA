#include <bits/stdc++.h>
using namespace std;

void helper(int ind, string &s, vector<string> &ans)
{
    if (ind == s.size())
    {
        ans.push_back(s);
        return;
    }
    for (int i = ind; i < s.size(); i++)
    {
        swap(s[i], s[ind]);
        helper(ind + 1, s, ans);
        swap(s[i], s[ind]);
    }
}

vector<string> findPermutations(string &s)
{
    // Write your code here.
    vector<string> ans;
    helper(0, s, ans);
    return ans;
}
