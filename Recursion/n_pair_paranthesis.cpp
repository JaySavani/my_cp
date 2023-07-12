#include <bits/stdc++.h>
using namespace std;

void helper(int open, int close, vector<string> &v, string op)
{
    if (open == 0 && close == 0)
    {
        v.push_back(op);
        return;
    }
    if (open != 0)
    {
        string op1 = op;
        op1.push_back('(');
        helper(open - 1, close, v, op1);
    }
    if (close > open)
    {
        string op1 = op;
        op1.push_back(')');
        helper(open, close - 1, v, op1);
    }
}

int main()
{
    int n = 4;
    vector<string> v;
    string oput = " ";
    int open;
    cin >> open;
    int close = open;
    helper(open, close, v, oput);

    for (auto p : v)
    {
        cout << p << " " << endl;
    }

    return 0;
}