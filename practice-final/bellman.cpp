#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int64_t u, v, c;
};

const int64_t MAX = 1e9;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t t = 1;
    // cin >> t;
    while (t--)
    {
        int64_t n, m;
        cin >> n >> m;
        vector<int64_t> adj[n];
        vector<Edge> edges;
        vector<int64_t> dis(n+1,MAX);
        for (int64_t i = 0; i < m; i++)
        {
            int64_t u, v, c;
            cin >> u >> v >> c;
            edges.push_back({u, v, c});
        }
        int64_t a, b;
        cin >> a >> b;
        dis[a] = 0;
        for (int64_t i = 0; i < n - 1; i++)
        {
            for (int64_t j = 0; j < m; j++)
            {
                int64_t u = edges[j].u;
                int64_t v = edges[j].v;
                int64_t c = edges[j].c;
                if (dis[u] + c < dis[v])
                    dis[v] = dis[u] + c;
            }
        }
        cout << dis[b];
    }
}