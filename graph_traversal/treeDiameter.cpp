#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V;
    cin >> V;
    vector<int> adj[V+1];
    for(int i = 0 ; i < V - 1 ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int extreme = -1;
    int max_height = 0;
    queue<pair<int,int>> q;
    vector<bool> visited(V+1,false);
    q.push({1,1});
    while(!q.empty())
    {
        int node = q.front().first;
        int height = q.front().second;
        q.pop();
        if(visited[node])
            continue;
        // cout << node << " --> " << height << '\n';
        visited[node] = true;
        if(height > max_height)
        {
            extreme = node;
            max_height = height;
        }
        for(auto& v : adj[node])
            q.push({v,height+1});
    }
    fill(visited.begin(),visited.end(),false);
    // cout << extreme << " - ";
    q.push({extreme,1});
    max_height = 0;
    while(!q.empty())
    {
        int node = q.front().first;
        int height = q.front().second;
        q.pop();
        if(visited[node])
            continue;
        // cout << node << " --> " << height << '\n';
        visited[node] = true;
        if(height > max_height)
        {
            extreme = node;
            max_height = height;
        }
        for(auto& v : adj[node])
            q.push({v,height+1});
    }
    // cout << extreme << " - ";
    cout << max_height;
}