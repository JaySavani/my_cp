#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    if (nums1.size() < nums2.size())
        swap(nums1, nums2);
    int m = nums1.size(), n = nums2.size();
    vector<int> dp(n + 1, 0);
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            cout << "i : " << i << " "
                 << "j : " << j << endl;
            if (nums1[i] == nums2[j])
            {
                cout << "number" << nums1[i] << endl;
                dp[j + 1] = 1 + dp[j];
                for (int i = 0; i < dp.size(); i++)
                {
                    cout << dp[i] << " ";
                }
                cout << endl;
            }
            else
            {
                dp[j + 1] = 0;
                for (int i = 0; i < dp.size(); i++)
                {
                    cout << dp[i] << " ";
                }
                cout << endl;
            }

            ans = max(ans, dp[j + 1]);
            cout << ans << endl;
        }
    }
    return 0;
}