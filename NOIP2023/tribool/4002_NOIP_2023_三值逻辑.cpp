//能确定的事情只有啊，今天感觉有点寂寞啊
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

int n, m;
struct Edge {
    // tp=3 initial
    // tp=2 0/1 F/T 2 Unkown
    // tp=0 v = point
    // tp=1 v = point but reverse
    int tp, tim, v;
    bool operator < (const Edge &q) const {
        return tim < q.tim;
    }
};
vector<Edge> G[N];
vector<pii> E[N];
vector<int> rE[N];
struct node {
    int tp, x, r;
};
map<pii, node> mp;
node dfs(int u, int k) {
    if (mp.count({u, k})) return mp[{u, k}];
    auto &res = mp[{u, k}];
    auto ed = G[u][k];
    if (ed.tp == 2) res = {ed.tp, ed.v, 0};
    else if (ed.tp == 3) res = {ed.tp, u, 0};
    else {
        int v = ed.v, t = ed.tim;
        int l = 0, r = (int)G[v].size() - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (G[v][mid].tim < t) l = mid + 1, ans = mid;
            else r = mid - 1;  
        }
        res = dfs(v, ans);
        res.r ^= ed.tp;
    }
    return res;
}
int vis[N], tv[N], cnt, deg[N], out[N];
void dfs(int u) {
    //cerr << "* " << u << '\n';
    if (vis[u]) return;
    cnt++;
    vis[u] = 1;
    for (auto [v, r] : E[u]) if (!vis[v]) dfs(v);
}

void MAIN() {
    mp.clear();
    cin >> n >> m;
    cnt = 0;
    for (int i = 1; i <= n; i++) tv[i] = 0, rE[i].clear(), G[i].clear(), E[i].clear(), vis[i] = 0, deg[i] = 0, out[i] = 0;
    for (int i = 1; i <= n; i++) {
        G[i].push_back({3, 0, 0});
    }
    string op;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> op;
        if (op == "+") {
            cin >> u >> v;
            G[u].push_back({0, i, v});
        } else if (op == "-") {
            cin >> u >> v;
            G[u].push_back({1, i, v});
        } else {
            cin >> u;
            v = (op == "T" ? 1 : op == "F" ? 0 : 2);
            G[u].push_back({2, i, v});
        }
    }
    for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
    vector<int> uu;
    for (int i = 1; i <= n; i++) {
        node res = dfs(i, (int)(G[i].size()) - 1);
        if (res.tp == 3) {
            if (res.x == i) {if (res.r == 1) uu.push_back(i);}
            else {rE[i].push_back(res.x), E[res.x].push_back({i, res.r}); deg[i]++; out[res.x]++;}
        } else if (res.tp == 2 && res.x == 2) uu.push_back(i);
        //cout <<"#" << i << ' '<< res.tp << ' ' << res.x << ' ' << res.r << '\n';
    }
    for (int u : uu) dfs(u);
    uu.clear();
    queue<int> q;
    for (int i = 1; i <= n; i++) if (deg[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        for (auto [v, r] : E[u]) {
            deg[v]--;
            if (!deg[v]) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) if (out[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        tv[u] = 1;
        q.pop();
        for (int v : rE[u]) {
            out[v]--;
            if (out[v] == 0) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) if (!vis[i] && !tv[i]) {
        int u = i, cc= 0;
        while (true) {
            for (auto [v, r] : E[u]) if (!tv[v]) {
                u = v;
                cc ^= r;
                break;
            }
            if (u == i) break;
        }
        u = i;
        while (true) {
            for (auto [v, r] : E[u]) if (!tv[v]) {
                tv[v] = 1;
                if (cc == 1) uu.push_back(v);
                u = v;
                break;
            }
            if (u == i) break;
        }
       // cout << i << ' ' << cc << '\n';
    }
    for (int u : uu) dfs(u);
    cout << cnt << '\n';
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T >> T;
    while (T--) MAIN();
    return 0;
}