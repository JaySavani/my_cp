#include <bits/stdc++.h>
using namespace std;

int coin_change_min(vector<int> coins, int sum)
{
    int n = coins.size();
    int t[n + 1][sum + 1];
    for (int i = 0; i < sum + 1; i++)
    {
        t[0][i] = INT_MAX - 1;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 0;
    }
    for (int j = 1; j < sum + 1; j++)
    {
        if (j % coins[0] == 0)
            t[1][j] = j;
        else
            t[1][j] = INT_MAX - 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
                // we have done INT_MAX -1 so that when we do +1 then overflow not occur
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int sum = 10;

    cout << coin_change_min(coins, sum);

    return 0;
}