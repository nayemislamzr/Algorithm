#include <bits/stdc++.h>
using namespace std;

void print(string s, int len)
{
    for(int i = 0 ; i < len ; i++)
        cout << s[i];
    cout << '\n';
}

void combination(string input, int cnt[], int left, string output, int len)
{
    print(output,len);
    for(int i = left ; i < input.length() ; i++)
    {
        if(!cnt[input[i]-'a'])
            continue;
        cnt[input[i]-'a']--;
        output[len] = input[i];
        combination(input,cnt,i,output,len+1);
        cnt[input[i]-'a']++;
    }
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    bool hasChar[26] = {false};
    int cnt[26] = {0};
    for(int i = 0 ; i < s.length() ; i++)
    {
        hasChar[s[i]-'a'] = true;
        cnt[s[i]-'a']++;
    }
    string input,output;
    for(int i = 0 ; i < 26 ; i++)
    {
        if(hasChar[i])
            input+=(i+'a');
    }
    output.resize(s.length());
    // sort(input.begin(),input.end());
    combination(input,cnt,0,output,0);
}