#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7;

struct Edge
{
    int u,v,c;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for(int i = 0 ; i < m ; i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        edges.push_back({u,v,c});
    }
    vector<int> weight(n+1,INF);
    weight[1] = 0;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(auto& edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int c = edge.c;
            if(weight[v] > weight[u]+c)
                weight[v] = weight[u]+c;
        }
    }
    for(int i = 1 ; i <= n ; i++)
        cout << i << " --> " << weight[i] << '\n';
}