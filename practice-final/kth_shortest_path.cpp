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
        int64_t n,m,k;
        cin >> n >> m >> k;
        vector<pii> adj[n+1];
        for(int64_t i = 0 ; i < m ; i++)
        {
            int64_t u,v,c;
            cin >> u >> v >> c;
            adj[u].push_back({v,c});
        }        
        int64_t a,b;
        cin >> a >> b;
        vector<priority_queue<int64_t>> dis(n+1);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        dis[1].push(0);
        pq.push({0,1});
        while(!pq.empty())
        {
            int64_t u = pq.top().second;
            int64_t d = pq.top().first;
            pq.pop();
            for(auto& x : adj[u])
            {
                int64_t v = x.first;
                int64_t c = x.second;
                if(dis[v].size() < k)
                {
                    dis[v].push(d+c);
                    pq.push({d + c,v});                    
                }
                else if(d + c < dis[v].top())
                {
                    dis[v].pop();
                    dis[v].push(d+c);
                    pq.push({d + c,v});
                }
            }
        }
        stack<int64_t> ans;
        while(!dis[b].empty())
        {
            ans.push(dis[b].top());
            dis[b].pop();
        }
        while(!ans.empty())
        {
            cout << ans.top() << ' ';
            ans.pop();
        }
    }
}