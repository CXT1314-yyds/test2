#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using ll = long long;
using db = double;
using ull = unsigned long long;
#define endl "\n"
#define vec vector
#define int128 __int128
#define gcd __gcd
#define str string
#define unmap unordered_map
#define db double
#define unset unordered_set
#define int long long
#define pii pair<int , int>

constexpr int inf = 1e9;
signed main() {
	IOS
    int n, m;
    cin >> n >> m;
    vec a(n, vec<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    vec<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        bool f1 = false;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            bool f2 = true;
            for (int k = 0; k < m; k++) {
                if (a[i][k] != a[j][k]) {
                    f2 = false;
                    break;
                }
            }
            if (f2) {
                f1 = true;
                break;
            }
        }
        if (f1) {
            ans[i] = -1;
            continue;
        }

        vec<vec<int>> o;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                o.push_back(a[j]);
            }
        }
        const int sz = static_cast<int>(o.size());
        if (sz == 0) {
            ans[i] = 0;
            continue;
        }

        vec<int> all(m, 0);
        for (int x = 0; x < m; x++) {
            int T_x = 0;
            for (int j = 0; j < sz; j++) {
                if (o[j][x] != a[i][x]) {
                    T_x |= 1 << j;
                }
            }
            all[x] = T_x;
        }

        const int ma = (1 << sz) - 1;
        vec dp(1 << sz, inf);
        vec<int> cnt(1 << sz, 0);
        vec<vec<int>> g(sz + 1);

        for (int msk = 0; msk < (1 << sz); msk++) {
            const int c = __builtin_popcount(msk);
            cnt[msk] = c;
            g[c].push_back(msk);
        }

        dp[0] = 0;
        for (int k = 0; k <= sz; k++) {
            for (const int msk : g[k]) {
                if (k == 0) continue;
                dp[msk] = inf;
                for (int x = 0; x < m; x++) {
                    const int new_m = msk & (~all[x]);
                    if (new_m == msk) continue;
                    if (dp[new_m] + 1 < dp[msk]) {
                        dp[msk] = dp[new_m] + 1;
                        if (dp[msk] == 1) break;
                    }
                }
            }
        }
        ans[i] = dp[ma];
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}