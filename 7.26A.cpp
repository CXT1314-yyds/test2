#include<bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
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

ostream &operator<<(ostream &os, int128 num) {
    if (num == 0) return os << "0";
    str s;
    while (num > 0) {
        s.push_back(static_cast<char>(48 + num % 10));
        num /= 10;
    }
    ranges::reverse(s);
    return os << s;
}

int a[30][30], v[30], mi[30];
unmap<int, int> mp[30];

signed main() {
    IOS
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    bool f = false;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (a[i][k] != a[j][k]) {
                    f = true;
                    break;
                }
            }
            if (!f) {
                v[i] = -1;
                v[j] = -1;
            }
        }
    }
    for (int j = 1 ; j <= m ; j++) {
        for (int i = 1 ; i <= n ; i++) {
            mp[j][a[i][j]]++;
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        if (v[i] == -1) cout << -1 << ' ';
        else {
            int mi = -1e9;
            for (int j = 1 ; j <= m ; j++) {
                mi = max(mi , mp[j][a[i][j]]);
            }
            cout << mi << ' ';
        }
    }
    return 0;
}
