#include <bits/stdc++.h>
using namespace std;

bool isPal(string str, int s, int e)
{
    while (s <= e)
    {
        if (str[s++] != str[e--])
        {
            return false;
        }
    }
    return true;
}

void helper(int ind, string s, vector<vector<string>> &ans, vector<string> &curr)
{
    if (ind == s.length())
    {
        ans.push_back(curr);
        return;
    }
    for (int i = ind; i < s.length(); i++)
    {
        if (isPal(s, ind, i))
        {
            curr.push_back(s.substr(ind, i - ind + 1));
            helper(i + 1, s, ans, curr);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s)
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> curr;
    helper(0, s, ans, curr);
    return ans;
}