#include <bits/stdc++.h>
using namespace std;

inline constexpr int _msb(int n) { return 31 - __builtin_clz(n); }
inline constexpr int _msb(int64_t n) { return 63 - __builtin_clzll(n); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int64_t n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int b[n][_msb(n)+1];
        for (int i = n - 1; i >= 0; i--)
        {
            b[i][0] = a[i];
            int index = _msb(n - i);
            for (int j = 1; j <= index; j++)
                b[i][j] = max(b[i][j - 1], b[i + (1 << (j - 1))][j - 1]);
        }
        int q;
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int sz = r-l+1;
            int index = l;
            int ans = -1;
            for(int i = _msb(sz) ; i >= 0 ; i--)
            {
                if((sz&(1<<i)) == 0)
                    continue;
                ans = max(ans,b[index][i]);
                index += (1<<i);
            }
            cout << ans << '\n';
        }
    }
}