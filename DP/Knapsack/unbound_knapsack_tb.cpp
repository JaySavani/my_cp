#include <bits/stdc++.h>
using namespace std;

// rod cutting is also variant of this

// variant coin change if we can select coin more then one time

int helper(vector<int> weight, vector<int> val, int c, int n)
{
    vector<vector<int>> t(n + 1, vector<int>(c + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (weight[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i][j - weight[i - 1]], t[i - 1][j]);
                // t[i][j] =  t[i][j - weight[i - 1]] + t[i - 1][j]; // if no of way or count is their then do + in between
                // above is for coin change
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][c];
}

int main()
{
    vector<int> weight = {5, 10, 23, 12, 2};
    vector<int> val = {30, 12, 2, 3, 4};
    int capacity = 30;
    int n = weight.size();
    cout << helper(weight, val, capacity, n);
    return 0;
}