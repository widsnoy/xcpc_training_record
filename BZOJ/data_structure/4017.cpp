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

int n, a[N];
ll s[N], b[N];
int tr[2][N];
void add(int tp, int x, int v) {
    for (; x <= n + 5; x += x & -x) tr[tp][x] += v;
}
int qry(int tp, int x) {
    int res = 0;
    for (; x; x -= x & -x) res += tr[tp][x];
    return res;
}
int qry(int tp, int l, int r) {
    if (l > r) return 0;
    return qry(tp, r) - qry(tp, l - 1);
}

void MAIN() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
    int ans1 = 0;
    ll ans2 = 0;
    for (int k = 0; k < 21; k++) {
        int w = (1 << k), g[2] = {0, 0};
        for (int i = 1; i <= n; i++) {
            int x = ((a[i] >> k) & 1);
            if (x == 0) g[0]++;
            else swap(g[0], g[1]), g[1]++;
            ans1 = (ans1 + g[1] * 1ll * w % mod) % mod;
        } 
    }
    cout << ans1 << ' ';
    for (int k = 0; k < 37; k++) {
        ll w = (1ll << k);
        vector<ll> v;
        for (int i = 0; i <= n + 5; i++) tr[0][i] = tr[1][i] = 0;
        for (int i = 0; i <= n; i++) {
            int x = ((s[i] >> k) & 1);
            b[i] = (s[i] & (w - 1));
            v.push_back(b[i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            int x = ((s[i] >> k) & 1);
            b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin() + 1;
            cnt ^= (qry(x ^ 1, 1, b[i]) & 1);
            cnt ^= (qry(x, b[i] + 1, n + 5) & 1);
            add(x, b[i], 1);
        }
        ans2 += cnt * w;
    }
    cout << ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}