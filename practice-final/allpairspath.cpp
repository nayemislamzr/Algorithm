#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t t = 1;
    // cin >> t;
    while (t)
    {
        int64_t n, m, q;
        cin >> n >> m >> q;
        if(!n)
            break;
        vector<vector<int64_t>> dis(n, vector<int64_t>(n, 1e9));
        for (int64_t i = 0; i < m; i++)
        {
            int64_t u, v, c;
            cin >> u >> v >> c;
            dis[u][v] = c;
        }
        for (int64_t i = 0; i < n; i++)
        {
            for (int64_t j = 0; j < n; j++)
            {
                for (int64_t k = 0; k < n; k++)
                {
                    if (dis[i][j] + dis[j][k] < dis[i][k])
                        dis[i][k] = dis[i][j] + dis[j][k];
                }
            }
        }
        while(q--)
        {
            int64_t u,v;
            cin >> u >> v;
            if(u == v)
                cout << 0 << '\n';
            else 
            {
                if(dis[u][v] >= 1e9)
                    cout << "Impossible\n";
                else 
                    cout << dis[u][v] << '\n';
            }
        }
        cout << '\n';
    }
}