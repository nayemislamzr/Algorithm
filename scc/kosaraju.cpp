#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<bool>& visited, stack<int>& st, int node)
{
    if(visited[node])
        return;
    visited[node] = true;
    for(auto& x : adj[node])
        dfs(adj,visited,st,x);
    st.push(node);
}

void revDfs(vector<int> adj[], vector<bool>& visited, int node)
{
    if(visited[node])
        return;
    visited[node] = true;
    cout << node << ' ';
    for(auto& x : adj[node])
        revDfs(adj,visited,x);
}

void doTrans(int n, vector<int> trans_adj[], vector<int> adj[])
{
    for(int i = 0 ; i < n ; i++)
        for(auto& it : adj[i])
            trans_adj[it].push_back(i);
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
    }
    stack<int> st;
    vector<bool> visited(n+1,false);
    dfs(adj,visited,st,0);
    vector<int> trans_adj[n+1];
    doTrans(n,trans_adj,adj);
    fill(visited.begin(),visited.end(),false);
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        if(visited[node])
            continue;
        cout << "SCC : ";
        revDfs(trans_adj,visited,node);
        cout << '\n';
    }
}