#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<bool>& vis, stack<int>& st, int node)
{
    vis[node] = true;
    for(auto& x : adj[node])
    {
        if(!vis[x])
            dfs(adj,vis,st,x);
    }
    st.push(node);
}

void revDfs(vector<int> trans_adj[], vector<bool>& vis, int node)
{
    vis[node] = true;
    cout << node << ' ';
    for(auto& x : trans_adj[node])
    {
        if(!vis[x])
            revDfs(trans_adj,vis,x);
    }
}

int main()
{
    int v,e;
    cin >> v >> e;
    vector<int> adj[v];
    for(int i = 0 ; i < e ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<bool> vis(v,false);
    stack<int> st;
    dfs(adj,vis,st,0);
    vector<int> trans_adj[v];
    for(int i = 0 ; i < v ; i++)
    {
        for(auto& x : adj[i])
            trans_adj[x].push_back(i);
    }
    fill(vis.begin(),vis.end(),false);
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        if(vis[node])
            continue;
        cout << "SCC : ";
        revDfs(trans_adj,vis,node);
        cout << '\n';
    }
}