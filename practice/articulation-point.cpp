#include<bits/stdc++.h>
using namespace std;

int t = 0;

void articulation_point(int node, vector<int> adj[], vector<int>& discovery_time,
                         vector<int>& low, vector<int>& parent, vector<bool>& ap)
{
    discovery_time[node] = low[node] = t++;
    int child = 0;
    for(auto& v : adj[node])
    {
        if(discovery_time[v] == -1) // not visited
        {
            child++;
            parent[v] = node;
            articulation_point(v,adj,discovery_time,low,parent,ap);
            low[node] = min(low[node],low[v]);
            if(parent[node] == -1 && child >= 2)
                ap[node] = true;
            else if(parent[node] != 1 && low[v] >= discovery_time[node])
                ap[node] = true;
        }
        else if(v != parent[node])
            low[node] = min(low[node],discovery_time[v]);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0 ; i < m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>discovery_time(n+1,-1);
    vector<int>low(n+1,-1);
    vector<int>parent(n+1,-1);
    vector<bool>ap(n+1,false);
    articulation_point(0,adj,discovery_time,low,parent,ap);
    for(int i = 0 ; i < n ; i++)
    {
        if(ap[i])
            cout << i << " ";
    }
}