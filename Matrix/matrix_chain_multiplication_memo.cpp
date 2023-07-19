#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
int t[1001][1001];

int solve(vector<int> v, int i, int j)
{
    if (i >= j)
        return 0;
    if (t[i][j] != -1)
        return t[i][j];
    for (int k = i; k <= j - 1; k++)
    {
        int temp = solve(v, i, k) + solve(v, k + 1, j) + v[i - 1] * v[k] * v[j];
        ans = min(ans, temp);
    }
    return t[i][j] = ans;
}

int main()
{
    vector<int> v = {10, 20, 10, 30};
    memset(t, -1, sizeof(t));

    cout << solve(v, 1, v.size() - 1);
    return 0;
}