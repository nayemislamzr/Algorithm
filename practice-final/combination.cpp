#include <bits/stdc++.h>
using namespace std;

void print(string& s, int len)
{
    for(int i = 0 ; i < len ; i++)
        cout << s[i];
    cout << '\n';
}

void combination(string& input, string& output, int cnt[], int left, int len)
{
    print(output,len);
    for(int i = left ; i < input.length() ; i++)
    {
        if(!cnt[input[i]-'a'])
            continue;
        cnt[input[i]-'a']--;
        output[len] = input[i];
        combination(input, output, cnt, i, len+1);
        cnt[input[i]-'a']++;
    }
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool hasChar[26] = {false};
    int cnt[26] = {0};
    for(int i = 0 ; i < n ; i++)
    {
        hasChar[s[i]-'a'] = true;
        cnt[s[i]-'a']++;
    }
    string input,output;
    for(int i = 0 ; i < 26 ; i++)
    {
        if(hasChar[i])
            input+= ('a'+i);
    }
    // sort(s.begin(),s.end());
    output.resize(n);
    combination(input,output,cnt,0,0);
}