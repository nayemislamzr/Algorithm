#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> adj[n+1];
        for(int i = 0 ; i < n - 1 ; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dis(n+1,-1);
        int root = 1;
        stack<int> st;
        st.push(root);
        dis[root] = 1;
        while(!st.empty())
        {
            int u = st.top();
            st.pop();
            for(auto& v : adj[u])
            {
                if(dis[v] == -1)
                {
                    dis[v] = dis[u]+1;
                    st.push(v);
                }
            }
        }
        int xtrm = root;
        for(int i = 1 ; i <= n ; i++)
        {
            if(dis[i] > dis[xtrm])
                xtrm = i;
        }
        fill(dis.begin(),dis.end(),-1);
        root = xtrm;
        st.push(root);
        dis[root] = 1;
        while(!st.empty())
        {
            int u = st.top();
            st.pop();
            for(auto& v : adj[u])
            {
                if(dis[v] == -1)
                {
                    dis[v] = dis[u]+1;
                    st.push(v);
                }
            }
        }
        cout << *max_element(dis.begin(),dis.end());
    }
}