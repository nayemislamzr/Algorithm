#include <bits/stdc++.h>
using namespace std;
#define INF 1e8

typedef pair<int,int> iPair;

int main()
{
    int v,e;
    cin >> v >> e;
    vector<iPair> adj[v];
    for(int i = 0 ; i < e ; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src = 0;
    priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
    vector<bool> vis(v,false);
    vector<int> par(v,-1), weight(v,INF);
    pq.push({0,src});
    weight[src] = 0;
    par[src] = src;
    int total_weight = 0;
    while(!pq.empty())
    {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        total_weight += w;
        for(auto& node : adj[u])
        {
            int v = node.first;
            int c = node.second;
            if(!vis[v] && weight[v] > c)
            {
                weight[v] = c;
                pq.push({weight[v],v});
                par[v] = u;
            }
        }
    }
    cout << total_weight;
}