#include <bits/stdc++.h>
using namespace std;

// other variant is target sum
// assign + - to arr and make arr such that sum is as given
// like arr[1,1,2,3]
// + 1 - 1 - 2 + 3 => 1st combination
// - 1 + 1 - 2 + 3 => 2nd combination
// + 1 + 1 + 2 - 3 => 3rd combination
// it is like this because s1 contains the +ve and s2 contains the -ve and diff is equal sum
// s1(1,1,2) - s2(3) = 1; // make 2 partition such that diff equal to sum

int subset_sum(vector<int> arr, int diff)
{
    int arrsum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        arrsum += arr[i];
    }

    // sum(s1) - sum(s2) = diff;
    // sum(s1) + sum(s2) = arrsum;
    // ---------------------------
    // sum(s1) = (diff + arrsum) / 2;

    int sum = (diff + arrsum) / 2;

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

    return t[n][sum];
}

int main()
{
    vector<int> v = {1, 1, 2, 3};
    int diff = 1;

    cout << subset_sum(v, diff) << endl;

    return 0;
}