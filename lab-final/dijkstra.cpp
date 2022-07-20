#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
typedef pair<int, int> iPair;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
    }
    int src, end;
    cin >> src >> end;
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<bool> visited(n + 1, false);
    vector<int> weight(n + 1, INF);
    pq.push({0, src});
    weight[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (auto &x : adj[u])
        {
            int v = x.second;
            int c = x.first;
            if (!visited[v] && weight[u] + c < weight[v])
            {
                weight[v] = weight[u] + c;
                pq.push({weight[v], v});
            }
        }
    }
    cout << weight[end];
}