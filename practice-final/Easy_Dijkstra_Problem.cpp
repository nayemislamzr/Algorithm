#include <bits/stdc++.h>
using namespace std;

typedef pair<int64_t,int64_t> pii;
const int64_t MAX = 1e9;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t t;
    cin >> t;
    while(t--)
    {
        int64_t n,m;
        cin >> n >> m;
        vector<pii> adj[n+1];
        for(int64_t i = 0 ; i < m ; i++)
        {
            int64_t u,v,c;
            cin >> u >> v >> c;
            adj[u].push_back({v,c});
        }
        int64_t a,b;
        cin >> a >> b;
        vector<int64_t> dis(n+1,MAX);
        dis[a] = 0;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,a});
        while(!pq.empty())
        {
            int64_t u = pq.top().second;
            pq.pop();
            for(auto& x : adj[u])
            {
                int64_t v = x.first;
                int64_t c = x.second;
                if(dis[v] > dis[u] + c)
                {
                    dis[v] = dis[u] + c;
                    pq.push({dis[v],v});
                }
            }
        }
        if(dis[b] >= 1e9)
            cout << "NO\n";
        else 
            cout << dis[b] << '\n';
    }
}