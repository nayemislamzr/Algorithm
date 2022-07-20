#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

void addEdge(vector <pair<int, int> > adj[], int u,
									int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}

void primMST(vector<pair<int,int> > adj[], int V)
{
	priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
    vector<int> parent(V,-1);
    vector<int> weight(V,INF);
    vector<bool> visited(V,false);
    int cost = 0, src = 0;
    pq.push({0,src});
    parent[src] = src;
    while(!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        cost += w;
        for(auto& x : adj[u])
        {
            int v = x.first;
            int c = x.second;
            if(!visited[v] && weight[v] > c)
            {
                weight[v] = c;
                parent[v] = u;
                pq.push({weight[v],v});
            }
        }
    }
    cout << cost << '\n';
}

int main()
{
	int V,E;
    cin >> V >> E;
	vector<iPair > adj[V];
    for(int i = 0 ; i < E ; i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        addEdge(adj,u,v,c);
    }
	primMST(adj, V);
	return 0;
}
