#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 5000 + 5;
int n, m, w[N], a[N];
ll dp[N];
vector<int> G[N];
ll dfs(int u) {
    if (dp[u] != 0) return dp[u];
    vector<pair<int, ll>> ve;
    for (int v : G[u]) if (w[v] < w[u]) {
        ve.push_back({w[v], dfs(v)});
    }
    vector<ll> f(w[u] + 1, 0);
    for (auto [x, y] : ve) {
        for (int i = w[u] - 1; i >= x; i--) f[i] = max(f[i], f[i - x] + y);
    }
    dp[u] = f[w[u] - 1] + 1;
    return dp[u];
}
void MAIN() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll res = 0;
    for (int i = 1; i <= n; i++) res += dfs(i) * a[i];
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
} 

