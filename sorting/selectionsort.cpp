#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    int compare = 0;
    int swap = 0;
    int step = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl;

    cout << "<-x-x  selection sort  x-x->";
    cout << endl;

    // main logic start

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            compare++;
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                swap++;

                cout << "step : " << step << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
                cout << endl;
                step++;
            }
        }
    }
    // main logic end

    cout << "sorted : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << "compare : " << compare << endl;
    cout << "swap : " << swap << endl;

    return 0;
}