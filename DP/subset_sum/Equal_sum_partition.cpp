#include <bits/stdc++.h>
using namespace std;

bool subset_sum(int arr[], int sum, int n)
{
    bool t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = true;
    }
    for (int i = 1; i < sum + 1; i++)
    {
        t[0][i] = false;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = ((t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]));
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}

bool equal_sum_par(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    if (sum % 2 != 0)
        return 0;
    else if (sum % 2 == 0)
    {
        return subset_sum(a, sum / 2, n);
    }
}

int main()
{
    int a[] = {2, 4, 6, 1, 4, 1};
    int n = 6;
    cout << equal_sum_par(a, n);

    return 0;
}