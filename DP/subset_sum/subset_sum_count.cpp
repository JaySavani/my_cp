#include <bits/stdc++.h>
using namespace std;

int subset_sum(vector<int> arr, int sum)
{
    int n = arr.size();
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }
    for (int i = 1; i < sum + 1; i++)
    {
        t[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = ((t[i - 1][j - arr[i - 1]]) + (t[i - 1][j]));
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < sum + 1; j++)
    //     {
    //         cout << t[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return t[n][sum];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum;
    cin >> sum;

    cout << subset_sum(a, sum) << endl;

    return 0;
}