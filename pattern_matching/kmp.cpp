#include <bits/stdc++.h>
using namespace std;

void buildLPS(int lps[],string s)
{
    int l = 0,r = 1;
    int n = s.length();
    while(r < n)
    {
        if(s[l] == s[r])
        {
            lps[r] = l+1;
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
    int lps[pattern.length()] = {0};
    buildLPS(lps,pattern);
    int i = 0, j = 0;
    vector<int> indexes;
    while(i < text.length())
    {
        if(text[i] == pattern[j])
        {
            j++;
            if(j == pattern.length())
                indexes.push_back(i-pattern.length()+1);
        }
        else if(j)
            j = lps[j-1]+1;
        i++;
    }
    for(auto& index : indexes)
        cout << index << '\n';
}