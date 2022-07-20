#include <bits/stdc++.h>
using namespace std;
#define INF 1e8

int main()
{
    int n,m;
    cin >> n >> m;
    int src, end;
    vector<pair<int,int>> adj[n+1];
    for(int i = 0 ; i < m ; i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
    }
    cin >> src >> end;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distance(n+1,INF);
    pq.push({0,src});
    distance[src] = 0;
    vector<bool> visited(n+1,false);
    while(!pq.empty())
    {
        int top_node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(visited[top_node])
            continue;
        visited[top_node] = true;
        for(auto& node : adj[top_node])
        {
            if(cost + node.second < distance[node.first])
            {
                distance[node.first] = cost + node.second;
                pq.push({distance[node.first],node.first});
            }
        }
    }
    cout << distance[end];
}