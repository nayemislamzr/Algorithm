#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> adj[n+1];
        for(int i = 0 ; i < m ; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int a,b;
        cin >> a >> b;
    }
}