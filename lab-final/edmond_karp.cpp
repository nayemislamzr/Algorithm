#include <bits/stdc++.h>
using namespace std;

const int MAX_FLOW_CAPACITY = 1000;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int adj[n][n];
        for (int i = 0; i < n; i++)
            memset(adj[i], 0, sizeof(adj[i]));
        for (int i = 0; i < m; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u][v] = c;
        }
        int src,sink;
        cin >> src >> sink;
        int max_flow = 0;
        while(true)
        {
            queue<int> q;
            vector<bool> vis(n,false);
            vector<int> par(n,-1);
            q.push(src);
            while(!q.empty())
            {
                int u = q.front();
                vis[u] = true;
                q.pop();
                for(int v = 0 ; v < n ; v++)
                {
                    if(!vis[v] && adj[u][v] > 0)
                    {
                        par[v] = u;
                        q.push(v);
                    }
                }
            }
            if(par[sink] == -1)
                break;
            int node = sink;
            vector<int> path;
            while(node != src)
            {
                path.push_back(node);
                node = par[node];
            }
            path.push_back(src);
            int bottleneck = MAX_FLOW_CAPACITY;
            int k = path.size();
            for(int i = k-1 ; i >= 1 ; i--)
            {
                int u = path[i];
                int v = path[i-1];
                bottleneck = min(bottleneck,adj[u][v]);
            }
            for(int i = k-1 ; i >= 1 ; i--)
            {
                int u = path[i];
                int v = path[i-1];
                adj[u][v] -= bottleneck;
                adj[v][u] += bottleneck;
            }
            max_flow += bottleneck;
        }
        cout << max_flow << '\n';
    }
}