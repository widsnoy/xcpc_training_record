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

const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int n, m, k;
int deg[N];
vector<int> G[N];

int fpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b) {
        ll d = exgcd(b, a % b, y, x);
        return y -= a / b * x, d;
    } else return x = 1, y = 0, a;
}
int getinv(int v) {
    return fpow(v, mod - 2);
    // ll x, y;
    // exgcd(v, mod, x, y);
    // return (x % mod + mod) % mod;
}

void MAIN() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        v += n;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    int ans = 0;
    for (int u = 1; u <= n; u++) {
        int res = 1;
        for (int v : G[u]) if (deg[v] > 0) {
            res = res * 1ll * (deg[v] - 1) % mod * getinv(deg[v]) % mod;
        }
        res = (mod + 1 - res) % mod;
        ans += res;
        ans %= mod;
    }
    cout << "modint\n";
    cout << ans << ' ';
    ans = 0;
    for (int u = n + 1; u <= n + m; u++) {
        int res = 1;
        for (int v : G[u]) if (deg[v] > 0) {
            res = res * 1ll * (deg[v] - 1) % mod * getinv(deg[v]) % mod;
        }
        res = (mod + 1 - res) % mod;
        ans += res;
        ans %= mod;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}