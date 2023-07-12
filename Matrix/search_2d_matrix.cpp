#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int i = 0;
    int j = n - 1;

    while (j >= 0 && i < m)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] < target)
            i++;
        else
            j--;
    }
    return false;
}

int main()
{
    return 0;
}
