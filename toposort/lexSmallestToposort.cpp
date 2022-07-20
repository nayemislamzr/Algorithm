#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n,m;
    cin >> n >> m;
    vector<int> adj[n+1], indegree(n+1,0);
    for(int i = 0 ; i < m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!indegree[i])
            q.push(i);
    }
    vector<int> res;
    while(!q.empty())
    {
        int curr_node = q.top();
        res.push_back(curr_node);
        q.pop();
        for(auto& node : adj[curr_node])
        {
            indegree[node]--;
            if(!indegree[node])
                q.push(node);
        }
    }
    for(int i = 0 ; i < res.size() ; i++)
        cout << res[i] << (i != n-1 ? "->" : "");
}