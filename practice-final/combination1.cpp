#include <bits/stdc++.h>
using namespace std;

void print(string& s, int len)
{
    if(len != 3)
        return;
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
        combination(input,output,cnt,i,len+1);
        cnt[input[i]-'a']++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        string s,t;
        cin >> s;
        t = s;
        int cnt[26] = {0};
        for(int i = 0 ; i < s.length() ; i++)
            cnt[s[i]-'a']++;
        sort(s.begin(),s.end());
        combination(s,t,cnt,0,0);
    }
}