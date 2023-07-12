
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 1 && arr[i] < n)
            {
                int ele = arr[i];
                int chair = arr[i] - 1;
                if (arr[chair] != ele)
                {
                    swap(arr[chair], arr[i]);
                    i--;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i + 1 != arr[i])
                return i + 1;
        }
        return n + 1;
        // Your code here
    }
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main()
{

    // taking testcases
    // } Driver Code Ends
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        // input number n
        int n;
        cin >> n;
        int arr[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        // calling missingNumber()
        cout << ob.missingNumber(arr, n) << endl;
    }
    return 0;
}
