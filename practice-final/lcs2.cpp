#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
int dp[MAX][MAX];

int lcs(string& s1, string& s2, int i, int j, int n, int m)
{
    if(i == n || j == m)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s1[i] == s2[j])
        return dp[i][j] = 1+lcs(s1,s2,i+1,j+1,n,m);
    return dp[i][j] = max(lcs(s1,s2,i+1,j,n,m), lcs(s1,s2,i,j+1,n,m));
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    memset(dp,-1,sizeof(dp));
    cout << lcs(s1,s2,0,0,n,m);
}