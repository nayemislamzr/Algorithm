#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, -1000));
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u][v] = c;
        adj[v][u] = 0;
    }
    int src, sink;
    cin >> src >> sink;
    int flow = 0;
    while (true)
    {
        queue<int> q;
        set<int> vis;
        map<int, int> par;
        q.push(src);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v = 1; v <= n; v++)
            {
                if (adj[u][v] > 0 && vis.find(v) == vis.end())
                {
                    vis.insert(v);
                    par[v] = u;
                    q.push(v);
                }
            }
        }
        if (par.find(sink) == par.end())
            break;
        // cout << par[sink] << '\n';
        vector<int> path;
        int node = sink;
        while (node != src)
        {
            path.push_back(node);
            node = par[node];
        }
        path.push_back(src);
        int bottleneck = 10000;
        for (int i = 0; i < path.size() - 1; i++)
        {
            int u = path[i + 1];
            int v = path[i];
            // cout << u << ' ';
            bottleneck = min(bottleneck, adj[u][v]);
        }
        // cout << '\n';
        // cout << bottleneck << '\n';
        for (int i = 0; i < path.size() - 1; i++)
        {
            int u = path[i + 1];
            int v = path[i];
            adj[u][v] -= bottleneck;
            adj[v][u] += bottleneck;
        }
        flow += bottleneck;
    }
    cout << flow;
}