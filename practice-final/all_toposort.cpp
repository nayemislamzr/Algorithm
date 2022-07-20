#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> res;

void dfs(int node, vector<int> adj[], vector<int>& indegree, vector<bool>& visited, vector<int>& ohYeah)
{
    bool flag = false;
    for(int i = 0 ; i < n ; i++)
    {
        if(visited[i] || indegree[i])
            continue;
        visited[i] = true;
        for(auto& x : adj[i])
            indegree[x]--;
        ohYeah.push_back(i);
        dfs(i,adj,indegree,visited,ohYeah);
        for(auto& x : adj[i])
            indegree[x]++;
        ohYeah.pop_back();
        visited[i] = false;
        flag = true;
    }
    if(!flag)
        res.push_back(ohYeah);
}

int main()
{
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<int> indegree(n+1,0);
    for(int i = 0 ; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    vector<bool> visited(n+1,false);
    vector<int> ohYeah;
    dfs(0,adj,indegree,visited,ohYeah);
    for(auto& x : res)
    {
        cout << "SCC : ";
        for(auto& y : x)
            cout << y << ' ';
        cout << '\n';
    }
}