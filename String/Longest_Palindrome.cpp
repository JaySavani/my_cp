#include <bits/stdc++.h>
using namespace std;

string longestPalin(string s)
{
    int start = 0;
    int maxl = 1;
    for (int i = 0; i < s.size(); i++)
    {
        // even
        int l = i - 1;
        int r = i;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            if (r - l + 1 > maxl)
            {
                maxl = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }

        // odd
        l = i - 1;
        r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            if (r - l + 1 > maxl)
            {
                maxl = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    }
    return s.substr(start, maxl);
}

int main()
{

    return 0;
}