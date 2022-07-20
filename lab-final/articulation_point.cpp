#include <bits/stdc++.h>
using namespace std;

int t = 0;

void articulation_point(vector<int> adj[], int u, vector<int> &discovery_time, vector<int> &low,
                        vector<int> &parent, vector<bool> &ap)
{
    discovery_time[u] = low[u] = t++;
    int child = 0;
    for(auto& v : adj[u])
    {
        if(discovery_time[v] == -1)
        {
            child++;
            parent[v] = u;
            articulation_point(adj,v,discovery_time,low,parent,ap);
            low[u] = min(low[u],low[v]);
            if(parent[u] == -1 && child > 1)
                ap[u] = true;
            if(parent[u] != -1 && low[v] > discovery_time[u])
                ap[u] = true;
        }
        else if(v != parent[u])
            low[u] = min(low[u],discovery_time[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> ap(n, false);
    vector<int> discovery_time(n, -1);
    vector<int> low(n, -1);
    vector<int> parent(n, -1);
    articulation_point(adj, 0, discovery_time, low, parent, ap);
    for (int i = 0; i < n; i++)
        cout << ap[i] << ' ';
}