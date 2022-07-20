#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    for(int i = 0 ; i < m ; i++)
    {
        int u,v,c; 
        cin >> u >> v >> c;
        adj[u].push_back({c,v});
    }
    int src,end;
    cin >> src >> end;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> visited(n+1, false);
    vector<int> weight(n+1, INF);
    pq.push({0,src});
    weight[src] = 0;
    while(!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        if(visited[node])
            continue;
        visited[node] = true;
        for(auto& x : adj[node])
        {
            int c = x.first;
            int v = x.second;
            if(!visited[v] && weight[v] > weight[node] + c)
            {
                weight[v] = weight[node] + c;
                pq.push({weight[v],v});
            }
        }
    }
    cout << weight[end];
}