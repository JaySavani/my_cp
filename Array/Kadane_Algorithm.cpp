#include <bits/stdc++.h>

using namespace std;
// Kadane's Algorithm is an efficient algorithm for finding the maximum subarray sum
// in a given array of integers.

// The algorithm works by iteratively scanning the array from left to right, keeping track
// of the maximum subarray sum seen so far. At each step, it considers whether adding the current
// element to the previous subarray sum (i.e., extending the subarray) would result in a larger sum
// than the current element alone. If the sum of the current element and the previous subarray sum
// is greater than the current element itself, it updates the maximum subarray sum. If the current
// element alone is greater, the algorithm starts a new subarray from that element.

long long maxSubarraySum(int arr[], int n)
{
    long long ans = INT_MIN, curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr = curr + arr[i];
        ans = max(ans, curr);
        // By KADANE'S ALGO jaise hi sum negative hojaye wahin chordo usko
        if (curr < 0)
        {
            curr = 0;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    long long max_sum = maxSubarraySum(arr, size);
    cout << "Maximum subarray sum: " << max_sum << endl;
    return 0;
}
