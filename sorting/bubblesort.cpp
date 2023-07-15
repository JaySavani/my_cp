#include <bits/stdc++.h>
using namespace std;

int compare = 0;
int swaps = 0;
int step = 1;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
    swaps++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl;

    cout << "<-x-x  bubble sort  x-x->";

    cout << endl;

    // main logic start

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            compare++;
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);

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
    cout << "swap : " << swaps << endl;

    return 0;
}