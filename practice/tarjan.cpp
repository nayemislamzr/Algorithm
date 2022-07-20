#include <bits/stdc++.h>
using namespace std;

int t = 0;

void tarjan(int node, vector<int> adj[], stack<int>& st, vector<int>& discovery_time, vector<int>& low, vector<bool>& inStack)
{
    discovery_time[node] = low[node] = t++;
    st.push(node);
    inStack[node] = true;
    for(auto& v : adj[node])
    {
        if(discovery_time[v] == -1) // not visited
        {
            tarjan(v,adj,st,discovery_time,low,inStack);
            low[node] = min(low[node],low[v]);
        }
        else if(inStack[v]) // back-edge
        {
            low[node] = min(low[node],discovery_time[v]);
        }

    }
    if(low[node] == discovery_time[node])
    {
        cout << "SCC : ";
        while(st.top() != node)
        {
            int v = st.top();
            cout << v << ' ';
            st.pop();
        }
        cout << st.top();
        st.pop();
        cout << '\n';
    }
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
    vector<int> discovery_time(n+1,-1), low(n+1,-1);
    vector<bool> inStack(n+1, false);
    stack<int> st;
    tarjan(0,adj,st,discovery_time,low,inStack);
}