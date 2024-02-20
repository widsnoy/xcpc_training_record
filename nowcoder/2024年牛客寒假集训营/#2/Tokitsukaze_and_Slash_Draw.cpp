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
const int N = 5000 + 5;

int n, m, k;
vector<pii> G[N];
int vis[N];
ll dis[N];
int trans(int x, int y) {
    x += y;
    if (x > n) x -= n;
    return x;
}
void MAIN() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        vector<pii>().swap(G[i]);
        vis[i] = 0;
        dis[i] = 1e18;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 1; j <= n; j++) {
            int u = j, v = trans(u, a);
            //cout << u << ' ' << v << '\n';
            G[u].push_back({v, b});
        }
    }
    priority_queue<pair<ll, int>> q;
    dis[k] = 0;
    q.push({0, k});
    while (!q.empty()) {
        int u = q.top().se;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : G[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
    if (dis[n] == 1e18) dis[n] = -1;
    cout << dis[n] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}