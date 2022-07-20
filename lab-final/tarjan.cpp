#include <bits/stdc++.h>
using namespace std;

int t = 0;
void tarjan(vector<int> adj[], int u, vector<int> &discovery_time, vector<int> &low, vector<bool> &inStack, stack<int> &st)
{
    discovery_time[u] = low[u] = t++;
    st.push(u);
    inStack[u] = true;
    for (auto &v : adj[u])
    {
        if (discovery_time[v] == -1)
        {
            tarjan(adj, v, discovery_time, low, inStack, st);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v])
            low[u] = min(low[u], discovery_time[v]);
    }
    if (discovery_time[u] == low[u])
    {
        cout << "SCC : ";
        while (st.top() != u)
        {
            cout << st.top() << ' ';
            inStack[st.top()] = false;
            st.pop();
        }
        cout << st.top() << '\n';
        inStack[st.top()] = false;
        st.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> discovery_time(n, -1), low(n, -1);
    vector<bool> inStack(n, false);
    stack<int> st;
    tarjan(adj, 0, discovery_time, low, inStack, st);
}