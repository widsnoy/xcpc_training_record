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
const int N = 1e5 + 5;

int n, m, faz[N], dep[N], st[N], dp[(1 << 21) + 5];
vector<int> G[N];
pii a[25];

void dfs(int u, int fa) {
    faz[u] = fa, dep[u] = dep[fa] + 1;
    for (int v : G[u]) if (v != fa) dfs(v, u);  
}

void MAIN() {
    cin >> n;
    for (int i = 1; i <= n; i++) vector<int>().swap(G[i]), st[i] = 0;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> a[i].fi >> a[i].se;
    dfs(1, 0);
    for (int k = 1; k <= m; k++) {
        int u = a[k].fi, v = a[k].se;
        if (dep[u] < dep[v]) swap(u, v);
        while (dep[u] > dep[v]) {
            st[u] |= (1 << (k - 1));
            u = faz[u];
        }
        while (u != v) {
            st[u] |= (1 << (k - 1));
            st[v] |= (1 << (k - 1));
            u = faz[u], v = faz[v];
        }
    }
    int mask = (1 << m) - 1;
    for (int i = 1; i <= mask; i++) dp[i] = 1e9;
    set<int> S;
    for (int i = 2; i <= n; i++) S.insert(st[i]);
    for (int x : S) {
        for (int i = 0; i <= mask; i++) dp[i | x] = min(dp[i | x], dp[i] + 1);
    }
    cout << dp[mask] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}