#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<int> parent(n+1);
    for(int i = 1 ; i <= n ; i++)
        parent[i] = i;
    function<int(int)> getParent = [&](int x)
    {
        if(parent[x] == x)
            return x;
        return getParent(parent[x]);
    };
    for(int i = 0 ; i < m ; i++)
    {
        int u,v;
        cin >> u >> v;
        if(getParent(u) != getParent(v))
            parent[u] = parent[v];
    }
    int q;
    cin >> q;
    auto isFriend = [&](int x, int y)
    {
        return getParent(x) == getParent(y);
    };
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        if(isFriend(x,y))
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}