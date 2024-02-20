#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 1e5 + 5;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b) {
        ll d = exgcd(b, a % b, y, x);
        return y -= a / b * x, d;
    } else return x = 1, y = 0, a;
}
int l[N], s[N], n, m, h;
struct node {
    int v, r, t;
};
void MAIN() {
    cin >> n >> m >> h;
    vector<node> G[n + 1];
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ll a = l[u] - l[v], b = s[v] - s[u];
        ll x, y;
        int g = exgcd(b, h, x, y);
        if (a % g != 0) continue;
        x *= a / g;
        g = abs(g);
        x = (x % (h / g) + h / g) % (h / g);
        G[u].push_back({v, h / g, x});
        G[v].push_back({u, h / g, x}); 
    }
    vector<ll> dis(n + 1, 1e16);
    vector<int> vis(n + 1, 0);
    priority_queue<pair<ll, int>> q;
    q.push({0, 1});
    dis[1] = 0;
    while (!q.empty()) {
        int u = q.top().se;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, r, t] : G[u]) {
            ll w = (dis[u] - t + r - 1) / r * r + t - dis[u] + 1;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
    if (dis[n] == 1e16) dis[n] = -1; 
    cout << dis[n] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
} 

