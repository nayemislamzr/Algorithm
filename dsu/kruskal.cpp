#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u,v,c;
    bool operator<(Edge& other)
    {
        return (c < other.c);
    }
};

int main()
{
    int V,E;
    cin >> V >> E;
    vector<Edge> edges;
    vector<int> parent(V);
    for(int i = 0 ; i < V ; i++)
        parent[i] = i;
    function<int(int)> getParent = [&](int x)
    {
        if(parent[x] == x)
            return x;
        return parent[x] = getParent(parent[x]);
    };
    for(int i = 0 ; i < E ; i++)
    {
        int u,v,c;
        cin >> u >> v >> c; 
        edges.push_back({u,v,c});
    }
    sort(edges.begin(),edges.end());
    vector<Edge> result;
    int total_weight = 0;
    for(auto& edge : edges)
    {
        if(getParent(edge.u) == getParent(edge.v))
            continue;
        total_weight += edge.c;
        result.push_back(edge);
        parent[edge.v] = parent[edge.u];
    }
    cout << "Total Weight : " << total_weight << '\n';
    for(auto& edge : result)
        cout << edge.u << " - " << edge.v << " - " << edge.c << "\n";
}