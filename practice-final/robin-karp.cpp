#include <bits/stdc++.h>
using namespace std;

bool evaluate(string& text, string& pattern, int index, int len)
{
    for(int i = index ; i < index + len ; i++)
    {
        if(text[i] != pattern[i - index])
            return false;
    }
    return true;
}

inline constexpr int val(char c)
{
    return c-'a'+1;
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;
    int n = text.length(), m = pattern.length();
    int temp = 1;
    int p = 101, patternHash = 0, textHash = 0;
    for(int i = 0 ; i < m ; i++)
    {
        patternHash += val(pattern[i])*temp;
        temp*=p;
    }
    int r = 0, l = 0;
    temp = 1;
    vector<int> indexes;
    while(r < n)
    {
        if(r < m)
        {
            textHash += val(text[r])*temp;
            if(r != m-1)
                temp*=p;
            else if(textHash == patternHash && evaluate(text,pattern,l,m))
                indexes.push_back(l);
            r++;
        }
        else 
        {
            textHash -= val(text[l]);
            textHash /= p;
            textHash += val(text[r])*temp;
            if(textHash == patternHash && evaluate(text,pattern,l+1,m))
                indexes.push_back(l+1);
            l++;
            r++;
        }
    }
    for(auto& index : indexes)
        cout << index << ' ';
}