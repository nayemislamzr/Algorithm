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
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<bool> visited(V+1,false);
    vector<int> weight(V+1,INF), parent(V+1,-1);
    int src = 0;
    pq.push({0,src});
    parent[src] = src;
    weight[src] = 0;
    int total_weight = 0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(visited[u])
            continue;
        total_weight += w;
        visited[u] = true;
        for(auto& x : adj[u])
        {
            int v = x.first;
            int c = x.second;
            if(!visited[v] && weight[v] > c)
            {
                weight[v] = c;
                pq.push({weight[v],v});
                parent[v] = u;
            }
        }
    }
    cout << "Total Weight : " << total_weight << '\n';
    for(int i = 0 ; i < V ; i++)
        cout << i << " - " << parent[i] << " - " << weight[i] << '\n';
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
