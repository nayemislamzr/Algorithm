#include <bits/stdc++.h>
using namespace std;

int t = 0;

void tarjan(int node, vector<int> adj[], vector<int>& discovery_time, vector<int>& low, vector<int>& parent)
{
    discovery_time[node] = low[node] = t++;
    for(auto& v : adj[node])
    {
        if(discovery_time[v] == -1) // not visited
        {
            parent[v] = node;
            tarjan(v,adj,discovery_time,low,parent);
            low[node] = min(low[node],low[v]);
        }
        else if(v != parent[node]) // back-edge
            low[node] = min(low[node],discovery_time[v]);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0;  i < m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    vector<int> discovery_time(n+1,-1), low(n+1,-1), parent(n+1,-1);
    tarjan(0,adj,discovery_time,low,parent);
    vector<pair<int,int>> bridges;
    for(int i = 1 ; i < n ; i++)
    {
        if(low[i] > discovery_time[parent[i]])
            bridges.push_back({i,parent[i]});
    }
    for(auto& bridge : bridges)
        cout << bridge.first << ' ' << bridge.second << '\n';
}