#include <bits/stdc++.h>

using namespace std;

void insert(stack<int> &s, int temp)
{
    if (s.size() == 0 || s.top() <= temp)
    {
        s.push(temp);
        return;
    }
    int tp = s.top();
    s.pop();
    insert(s, temp);
    s.push(tp);
}

void sort(stack<int> &s)
{
    if (s.size() == 0)
        return;
    int temp = s.top();
    s.pop();
    sort(s);
    insert(s, temp);
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(1);
    s.push(6);
    s.push(5);
    s.push(-1);

    sort(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    // s.pop();

    return 0;
}