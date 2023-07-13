#include <iostream>
#include <vector>

using namespace std;

bool isPossibleDerivation(const vector<int> &q)
{
    vector<int> p;
    int i = 0;
    int n = q.size();

    for (int j = 0; j < n; j++)
    {
        if (q[j] != 1)
        {
            int subarrayLength = q[j];
            vector<int> subarray(q.begin() + j + 1, q.begin() + j + 1 + subarrayLength);

            if (subarray.size() != subarrayLength)
            {
                return false; // Invalid subarray length
            }

            p.insert(p.end(), subarray.begin(), subarray.end());
            j += subarrayLength;
        }
        else
        {
            p.push_back(q[j]);
        }
    }

    return (p == q);
}

int main()
{
    vector<int> q = {1, 7, 3, 8, 9, 7, 8, 9, 2};

    if (isPossibleDerivation(q))
    {
        cout << "q could have been derived from an array p." << endl;
    }
    else
    {
        cout << "q could not have been derived from an array p." << endl;
    }

    return 0;
}
