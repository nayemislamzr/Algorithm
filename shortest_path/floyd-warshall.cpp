#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1,vector<int>(n+1,INF));
    for(int i = 0 ; i < m ; i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        adj[u][v] = c;
    }
    for(int i = 1 ; i <= n ; i++)
        adj[i][i] = 0;
    for(int k = 1; k <= n ; k++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++) 
        {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
}