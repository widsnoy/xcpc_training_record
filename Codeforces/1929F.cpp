//复建...o.o
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 5e5 + 5;

int n, c, val[N], a[N], p[N], dfc;
vector<int> G[N];
void dfs(int u) {
    if (G[u][0] != -1) dfs(G[u][0]);
    p[++dfc] = u;
    if (G[u][1] != -1) dfs(G[u][1]);
}
int fpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}
int binom(int n, int m) {
    int a = 1, b = 1;
    for (int i = n - m + 1; i <= n; i++) a = a * 1ll * i % mod;
    for (int i = 1; i <= m; i++) b = b * 1ll * i % mod;
    return a * 1ll * fpow(b, mod - 2) % mod;
}
void MAIN() {
    cin >> n >> c;
    dfc = 0;
    for (int i = 1; i <= n; i++) {
        vector<int>().swap(G[i]);
        int lc, rc; cin >> lc >> rc >> val[i];
        G[i].push_back(lc);
        G[i].push_back(rc);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) a[i] = val[p[i]];
    a[n + 1] = c; a[0] = 1;
    int ans = 1;
    for (int i = 1, j = 0; i <= n + 1; i++) {
        if (a[i] != -1) {
            int l = a[j], r = a[i], len = i - j - 1;
            j = i;
            if (len == 0) continue;
            ans = ans * 1ll * binom(r - l + len, len) % mod;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}