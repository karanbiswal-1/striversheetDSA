#include <bits/stdc++.h>
using namespace std;

void solve(string &s, string &temp, int ind, vector<string> &ans, vector<string> &dic)
{
    int n = s.length();
    if (ind >= n)
    {
        if (find(dic.begin(), dic.end(), s.substr(ind)) != dic.end())
        {
            ans.push_back(temp);
        }
        return;
    }
    for (int i = ind; i < n; i++)
    {
        string curr = s.substr(ind, i - ind + 1);
        if (find(dic.begin(), dic.end(), curr) != dic.end())
        {
            string t = temp;
            temp += curr + " ";
            solve(s, temp, i + 1, ans, dic);
            temp = t;
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    string temp;

    solve(s, temp, 0, ans, dictionary);
    return ans;
}