#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> weight, vector<int> val, int capacity, int n, vector<vector<int>> &dp)
{
    if (n == 0 || capacity == 0)
        return 0;

    if (dp[n][capacity] != -1)
        return dp[n][capacity];

    if (weight[n - 1] <= capacity)
    {
        return dp[n][capacity] = max(val[n - 1] + helper(weight, val, capacity - weight[n - 1], n - 1, dp), helper(weight, val, capacity, n - 1, dp));
    }
    else
    {
        return dp[n][capacity] = helper(weight, val, capacity, n - 1, dp);
    }
}

int main()
{
    vector<int> weight = {5, 10, 23, 12, 2};
    vector<int> val = {30, 12, 2, 3, 4};
    int capacity = 30;
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));

    cout << helper(weight, val, capacity, n, dp);

    return 0;
}