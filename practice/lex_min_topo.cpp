#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<int> indegree(n+1,0);
    for(int i = 0 ; i < m ; i++)
    {
        int u,v; 
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0 ; i < n ; i++)
    {
        if(!indegree[i])
            pq.push(i);
    }
    vector<bool> visited(n+1,false);
    while(!pq.empty())
    {
        int node = pq.top();
        pq.pop();
        if(visited[node])
            continue;
        cout << node << " ";
        visited[node] = true;
        for(auto& v : adj[node])
        {
            if(--indegree[v] == 0)
                pq.push(v);
        }
    }
}