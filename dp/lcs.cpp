#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
int dp[MAX][MAX];

int lcs(string& s1, string& s2, int i, int j)
{
    if(i == s1.length() || j == s2.length())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s1[i] == s2[j])
        return dp[i][j] = 1+lcs(s1,s2,i+1,j+1);
    return dp[i][j] = max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
}

void print(int n, int m)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() 
{
    string s1,s2;
    cin >> s1 >> s2;
    for(int i = 0 ; i < MAX ; i++)
        for(int j = 0 ; j < MAX ; j++)
            dp[i][j] = -1;
    cout << lcs(s1,s2,0,0) << '\n';
    // print(s1.length(),s2.length());
}