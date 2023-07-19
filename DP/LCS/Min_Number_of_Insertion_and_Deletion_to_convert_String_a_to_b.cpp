#include <bits/stdc++.h>
using namespace std;
// you have to convert string x to y with only insertion and deletion
// first you calculate lcs so from x other then lcs you can remove
// then lcs and othen string of y you have to add

// so at the end, covert a to lcs no of step=>a.size - lcs // deletion
// covert lcs to b no of step => b.size-lcs // insertion

//  deletion other variant is if you delete non subsequence char then string become palindrome
// and if you insert same char then from pair also we can get palindrome
// so for make palindrome => no of deletion = no of insertion => if we insert then palindrome become big

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
    string x = "choras";
    string y = "porus";
    int m = x.size();
    int n = y.size();
    int lcs = lcs_tb(x, y, m, n);

    cout << m - lcs + n - lcs;
    return 0;
}