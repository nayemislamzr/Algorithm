#include <bits/stdc++.h>
using namespace std;

typedef pair<int64_t, int64_t> pii;
const int MAX = 200005;

vector<int64_t> res;
vector<map<int64_t,bool>> dp(MAX);

int64_t solve(pii a[], int64_t i, int64_t n, vector<int64_t> &b, int64_t c, int64_t w)
{
    if (c >= (w + 1) / 2 && c <= w)
    {
        res = b;
        return 1;
    }
    if (c > w || i >= n)
        return 0;
    auto itr = dp[i].lower_bound(c);
    if(itr != dp[i].end())
    {
        bool besi = itr->second;
        if(besi)
            return 1;
        else 
        {
            if(itr == dp[i].begin())
            {
                if(itr->first == i)
                    return itr->second;
            }
            else 
            {
                itr--;
                if(itr->second)
                    return 1LL;
            }
        }
    }
    b.push_back(a[i].second);
    int64_t x = solve(a, i + 1, n, b, c + a[i].first, w);
    b.pop_back();
    int64_t y = solve(a, i + 1, n, b, c, w);
    dp[i].insert({c,x|y});
    return (x | y);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t t;
    cin >> t;
    while (t--)
    {
        int64_t n, w;
        cin >> n >> w;
        pii a[n];
        for (int64_t i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a, a + n);
        vector<int64_t> b;
        res.clear();
        for(int i = 0 ; i < MAX ; i++)
            dp[i].clear();
        if (solve(a, 0, n, b, 0, w))
        {
            cout << res.size() << '\n';
            for (int64_t i = 0; i < res.size(); i++)
                cout << res[i] + 1 << ' ';
            cout << '\n';
        }
        else
            cout << "-1\n";
    }
}