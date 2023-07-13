#include <bits/stdc++.h>
using namespace std;

vector<int> subset_sum(vector<int> arr, int sum)
{
    vector<int> ans;
    int n = arr.size();
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
    for (int k = 0; k <= sum / 2; k++) // sum/2 not sum+1
    {
        if (t[n][k] == 1)
            ans.push_back(k);
    }

    return ans;
}

int find_min(vector<int> v)
{
    int mini = INT_MAX;
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }

    vector<int> last_row = subset_sum(v, sum);

    for (int i = 0; i < last_row.size(); i++)
    {
        mini = min(mini, abs(sum - (2 * last_row[i])));
    }
    return mini;
}

int main()
{
    vector<int> v = {1, 20, 31, 5, 6, 1, 4};
    cout << find_min(v);
    return 0;
}