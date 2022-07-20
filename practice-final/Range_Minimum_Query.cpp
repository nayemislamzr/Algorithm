#include <bits/stdc++.h>
using namespace std;

inline constexpr int64_t _msb(int64_t n) { return 63 - __builtin_clzll(n); }

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t t = 1;
    // cin >> t;
    while (t--)
    {
        int64_t n;
        cin >> n;
        int64_t a[n];
        for (int64_t i = 0; i < n; i++)
            cin >> a[i];
        int64_t b[n][_msb(n) + 1];
        for (int64_t i = n - 1; i >= 0; i--)
        {
            b[i][0] = a[i];
            int64_t index = _msb(n - i);
            for (int64_t j = 1; j <= index; j++)
                b[i][j] = min(b[i][j - 1], b[i + (j >> 1) + 1][j - 1]);
        }
        int64_t q;
        cin >> q;
        while (q--)
        {
            int64_t l, r;
            cin >> l >> r;
            int64_t sz = r - l + 1;
            int64_t index = l;
            int64_t ans = INT32_MAX;
            for (int64_t i = _msb(sz); i >= 0; i--)
            {
                if (!(sz & (1 << i)))
                    continue;
                ans = min(ans, b[index][i]);
                index += (1 << i);
            }
            cout << ans << '\n';
        }
    }
}