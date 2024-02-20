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
int n, lim, a[N], b2[N], ib2[N];
int tr[N * 35][2], sum[N * 35], tot;
int fpow(int a, int b = mod - 2) {
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}
void add(int &x, int y) {
    ((x += y) >= mod) && (x -= mod);
}
void insert(int x, int val) {
    int u = 0;
    for (int k = 30; k >= 0; k--) {
        int v = ((x >> k) & 1);
        if (!tr[u][v]) tr[u][v] = ++tot;
        u = tr[u][v];
        add(sum[u], val);
    }
}
int qry(int x, int lim) {
    int u = 0;
    int res = 0;
    for (int k = 30; k >= 0; k--) {
        int v = ((x >> k) & 1);
        if ((lim >> k) & 1) {
            add(res, sum[tr[u][v]]);
            u = tr[u][v ^ 1];
        } else {
            u = tr[u][v];
        }
        if (!u) break;
    }
    add(res, sum[u]);
    return res;
}
void MAIN() {
    cin >> n >> lim;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = n;
    for (int i = 1; i <= n; i++) {
        int res = qry(a[i], lim);
        res = res * 1ll * b2[i - 1] % mod;
        //cerr << res << '\n';
        add(ans, res);
        insert(a[i], ib2[i]);
    }
    cout << ans << '\n';
    for (int i = 0; i <= tot; i++) memset(tr[i], 0, sizeof tr[i]), sum[i] = 0;
    tot = 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    b2[0] = 1, ib2[0] = 1;
    for (int i = 1; i < N; i++) add(b2[i], b2[i - 1]), add(b2[i], b2[i - 1]), ib2[i] = fpow(b2[i]);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}