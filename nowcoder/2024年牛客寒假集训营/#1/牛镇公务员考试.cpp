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
const int N = 1e5 + 5;
int n, a[N];
vector<pii> G[5][N];
vector<int> T[N];
int col[N], cur[N];
 
bool dfs(int u, int sta, const int c) {
    col[u] = c;
    cur[u] = sta;
    for (auto [v, w] : G[sta][u]) {
        if (col[v] == c) {
           // cout << c << ' ' << u << ' ' << v << ' ' << w << ' '<< cur[v] << '\n';
            if (cur[v] != w) return 0;
        } else {
            if (!dfs(v, w, c)) return 0;
        }
    }
    return 1;
}
void color(int u) {
    col[u] = 6;
    for (int v : T[u]) if (col[v] == -1) color(v);
}
void MAIN() {
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cin >> s;
        for (int k = 0; k < 5; k++) {
            G[k][i].push_back({a[i], s[k] - 'A'});
            G[s[k] - 'A'][a[i]].push_back({i, k});
            T[i].push_back(a[i]);
            T[a[i]].push_back(i);
        }
    }
    int res = 1;
    memset(col, -1, sizeof col);
    for (int i = 1; i <= n; i++) if (col[i] == -1) {
        color(i);
        int re = 0;
        for (int k = 0; k < 5; k++) {
            re += dfs(i, k, k);
        }
        res = re * 1ll * res % mod;
    }
    cout << res << '\n';
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    MAIN();
    return 0;
}