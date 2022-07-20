#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> res;
vector<vector<int>> toposorts;
vector<bool> visited(n+1,false);

void allPossibleToposort(vector<int> adj[], vector<int>& indegree, vector<bool>& visited)
{
    bool flag = false;
    for(int i = 1 ; i <= n ; i++)
    {
        if(visited[i] || indegree[i])
            continue;
        res.push_back(i);
        visited[i] = true;
        for(auto& node : adj[i])
            indegree[node]--;
        allPossibleToposort(adj,indegree,visited);
        visited[i] = false;
        for(auto& node : adj[i])
            indegree[node]++;
        res.pop_back();
        flag = true;
    }
    if(!flag)
        toposorts.push_back(res);
}

int main()
{
    cin >> n >> m;
    vector<int> adj[n+1], indegree(n+1,0);
    for(int i = 0 ; i < m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    allPossibleToposort(adj,indegree,visited);
    for(auto& sort : toposorts)
    {
        for(auto& x : sort)
        {
            cout << x << " ";
        }
        cout << '\n';
    }
}