#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    int ele1 = -1;
    int ele2 = -1;
    int c1 = 0;
    int c2 = 0;
    vector<int> v;

    for (int i : arr)
    {
        if (i == ele1)
        {
            c1++;
        }
        else if (i == ele2)
        {
            c2++;
        }
        else if (c1 == 0)
        {
            ele1 = i;
            c1 = 1;
        }
        else if (c2 == 0)
        {
            ele2 = i;
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    c1 = 0;
    c2 = 0;
    for (int i : arr)
    {
        if (i == ele1)
        {
            c1++;
        }
        else if (i == ele2)
        {
            c2++;
        }
    }
    if (c1 >= n / 3)
    {
        v.push_back(ele1);
    }
    if (c2 >= n / 3)
    {
        v.push_back(ele2);
    }
    sort(v.begin(), v.end());
    return v;
}

int main()
{
    vector<int> arr{7, 4, 4, 9, 7};
    vector<int> v = majorityElementII(arr);
    for (int i : v)
    {
        cout << i << " ";
    }
}