//能确定的事情只有啊，今天感觉有点寂寞啊
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
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

int n, a[N], b[N];
vector<int> G[N];
int dep[N], faz[N][21];
void pre(int u, int fa) {
    dep[u] = dep[fa] + 1;
    faz[u][0] = fa;
    for (int i = 1; i < 21; i++) faz[u][i] = faz[faz[u][i - 1]][i -1];
    for (int v : G[u]) if (v != fa) pre(v, u);
}
int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int d = dep[u] - dep[v];
    for (int i = 0; i < 21; i++) if (d & (1 << i)) u = faz[u][i];
    if (u == v) return u;
    for (int i = 20; i >= 0; i--) if (faz[u][i] != faz[v][i]) u = faz[u][i], v = faz[v][i];
    return faz[u][0];
}
int F(int u, int d) {
    for (int i = 0; i < 21; i++) if (d & (1 << i)) u = faz[u][i];
    return u;
}
struct node {
    int m, r, po, id;
};
ll ans[N];
vector<node> dat[N];
const int lim = 770;
ll g[lim + 5][lim + 5];
void dfs(int u, int fa) {
    for (int i = 1; i <= lim; i++) g[i][dep[u] % i] += a[u];
    for (node D : dat[u]) {
        if (D.m <= lim) ans[D.id] += D.po * g[D.m][D.r];
        else {
            int now = u;
            while (now) {
                ans[D.id] += D.po * a[now];
                now = F(now, D.m);
            }
        }
    }
    for (int v : G[u]) if (v != fa) {
        dfs(v, u);
    }
    for (int i = 1; i <= lim; i++) g[i][dep[u] % i] -= a[u];
}
void MAIN() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    pre(1, 0);
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i < n; i++) {
        int u = b[i], v = b[i + 1], lca = LCA(u, v), k;
        cin >> k;
        dat[u].push_back({k, dep[u] % k, 1, i});
        dat[v].push_back({k, dep[v] % k, 1, i});
        int det = (dep[lca] % k - dep[u] % k + k) % k;
        if (det == 0) det += k;
        int x = F(lca, det);
        dat[x].push_back({k, dep[u] % k, -1, i});
        det = (dep[lca] % k - dep[v] % k + k) % k;
        x = F(lca, det);
        dat[x].push_back({k, dep[v] % k, -1, i});
    }
    dfs(1, 0);
    for (int i = 1; i < n; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}