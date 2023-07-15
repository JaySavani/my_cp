#include <bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int m, int n, vector<vector<int>> &t)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (t[m][n] != -1)
        return t[m][n];
    if (x[m - 1] == y[n - 1])
    {
        return t[m][n] = 1 + lcs(x, y, m - 1, n - 1, t);
    }
    else
    {
        return t[m][n] = max(lcs(x, y, m, n - 1, t), lcs(x, y, m - 1, n, t));
    }
}

int main()
{
    string x = "choras";
    string y = "porus";
    int m = x.size();
    int n = y.size();
    vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));

    cout << lcs(x, y, m, n, t);
    return 0;
}