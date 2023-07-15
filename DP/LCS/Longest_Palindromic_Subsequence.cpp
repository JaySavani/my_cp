#include <bits/stdc++.h>
using namespace std;

// lps(a) = lcs(a,reverse(a));
// variant Minimum number of deletion in a string to make it a palindrome
// Minimum number of deletion = a.length - lps(a);

int lcs_tb(string x, string y, int m, int n)
{
    vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[m][n];
}

int main()
{
    string x = "abcawcba";
    string y = x;
    reverse(y.begin(), y.end());
    int m = x.size();
    int n = y.size();

    cout << lcs_tb(x, y, m, n);
    return 0;
}