#include <bits/stdc++.h>

using namespace std;

void insert(vector<int> &v, int temp)
{
    if (v.size() == 0 || v.back() <= temp)
    {
        v.push_back(temp);
        return;
    }
    int tp = v.back();
    v.pop_back();
    insert(v, temp);
    v.push_back(tp);
}

void sort(vector<int> &v)
{
    if (v.size() == 0)
        return;
    int temp = v.back();
    v.pop_back();
    sort(v);
    insert(v, temp);
}

int main()
{
    vector<int> arr = {-1, 5, 0, 4, 2, -4, 7, 6};
    sort(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}