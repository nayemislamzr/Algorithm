#include <bits/stdc++.h>
using namespace std;

int val(char c)
{
    return (c - 'a' + 1);
}

int main()
{
    string pattern, text;
    cin >> text >> pattern;
    int n, m;
    n = text.length();
    m = pattern.length();
    int p = 101, patternHash = 0, textHash = 0;
    int temp = 1;
    for (int i = 0; i < m; i++)
    {
        patternHash += (val(pattern[i]) * temp);
        temp *= p;
    }
    temp = 1;
    int left = 0, right = 0;
    vector<int> indexes;
    while (right < n)
    {
        if (right < m)
        {
            textHash += (val(text[right]) * temp);
            if(right != m-1)
                temp *= p;
            right++;
        }
        else
        {
            textHash -= val(text[left]);
            textHash /= p;
            textHash += (val(text[right]) * temp);
            if (patternHash == textHash)
            {
                bool flag = true;
                for (int i = 0; i < m; i++)
                {
                    if (pattern[i] != text[left + 1 + i])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    indexes.push_back(left+1);
            }
            left++;
            right++;
        }
    }
    for (auto &index : indexes)
        cout << index << '\n';
}