#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, c;
    bool operator<(Edge other)
    {
        return c < other.c;
    }
};

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> par(v);
    for (int i = 0; i < v; i++)
        par[i] = i;
    vector<Edge> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }
    sort(edges.begin(), edges.end());
    function<int(int)> getParent = [&](int u)
    {
        if (par[u] == u)
            return u;
        return par[u] = getParent(par[u]);
    };
    int cost = 0;
    for (auto &edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int u_par = getParent(u);
        int v_par = getParent(v);
        if (u_par == v_par)
            continue;
        cost += edge.c;
        par[v_par] = u_par;
    }
    cout << cost ;
}