#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    int dp[n+1][m+1];
    for(int i = 0 ; i <= n ; i++)
    {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(s1[i] == s2[j])
                dp[i+1][j+1] = dp[i][j]+1;
            else 
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
        }
    }
    
    // print dp array
    // for(int i = 0 ; i <= n ; i++)
    // {
    //     for(int j = 0 ; j <= m ; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[n][m];
}