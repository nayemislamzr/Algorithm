#include <bits/stdc++.h>
using namespace std;

void buildLPS(string& s, int lps[], int len)
{
    int l = 0, r = 1;
    while(r < len)
    {
        if(s[l] == s[r])
        {
            lps[r] = 1+l;
            l++;
            r++;
        }
        else 
        {
            if(l == 0)
                r++;
            else 
                l = lps[l-1];
        }
    }
}

int main()
{
    string text,pattern;
    cin >> text >> pattern;
    int n = text.length(), m = pattern.length();
    int lps[m];
    memset(lps,0,sizeof(lps));
    buildLPS(pattern, lps, m);
    int i = 0, j = 0;
    vector<int> indexes;
    while(i < n)
    {
        if(text[i] == pattern[j])
        {
            j++;
            if(j == m)
                indexes.push_back(i-m+1);
        }
        else if(j)
            j = lps[j-1]+1; 
        i++;
    }
    for(auto& index : indexes)
        cout << index << ' ';
}