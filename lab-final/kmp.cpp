#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string &s)
{
    int l = 0, r = 1, n = s.length();
    vector<int> lps(n, 0);
    while (r < n)
    {
        if (s[l] == s[r])
        {
            lps[r] = l + 1;
            l++;
            r++;
        }
        else
        {
            if (l == 0)
                r++;
            else
                l = lps[l - 1];
        }
    }
    return lps;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string pattern, text;
        cin >> text >> pattern;
        auto lps = buildLPS(pattern);
        int i = 0, j = 0, n = text.length();
        while (i < n)
        {
            if (text[i] == pattern[j])
            {
                j++;
                if (j == pattern.length())
                    cout << i << ' ';
            }
            else if (j)
                j = lps[j - 1] + 1;
            i++;
        }
        cout << '\n';
    }
}