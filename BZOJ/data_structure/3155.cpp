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

ll sum[N << 2], taga[N << 2], tagd[N << 2];
#define lc (p << 1)
#define rc ((p << 1) | 1)
#define mid ((l + r) >> 1)
int n, q;
ll a[N], s[N], ss[N];
void build(int p, int l, int r) {
    if (l == r) return sum[p] = ss[l], void();
    build(lc, l, mid), build(rc, mid + 1, r);
    sum[p] = sum[lc] + sum[rc];
}
ll qrys(ll a, ll d, ll len) {
    return (a + a + (len - 1) * d) * len / 2ll;
}
void pushdown(int p, int l, int r) {
    if (taga[p] == 0 && tagd[p] == 0) return;
    sum[lc] += qrys(taga[p], tagd[p], mid - l + 1);
    taga[lc] += taga[p], tagd[lc] += tagd[p];
    sum[rc] += qrys(taga[p] + (mid + 1 - l) * tagd[p], tagd[p], r - mid);
    taga[rc] += taga[p] + (mid + 1 - l) * tagd[p], tagd[rc] += tagd[p];
    taga[p] = tagd[p] = 0;
}
void add(int p, int l, int r, int L, int R, ll pos, ll td) {
    if (l > R || r < L) return;
    if (l >= L && r <= R) {
        ll ta = (l - pos + 1) * td;
        sum[p] += qrys(ta, td, r - l + 1);
        taga[p] += ta, tagd[p] += td;
        return;
    }
    pushdown(p, l, r);
    add(lc, l, mid, L, R, pos, td);
    add(rc, mid + 1, r, L, R, pos, td);
    sum[p] = sum[lc] + sum[rc];
}
ll qry(int p, int l, int r, int L, int R) {
    if (l > R || r < L) return 0;
    if (l >= L && r <= R) return sum[p];
    pushdown(p, l, r);
    return qry(lc, l, mid, L, R) + qry(rc, mid + 1, r, L, R);
}

void MAIN() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        ss[i] = ss[i - 1] + s[i];
    }
    build(1, 1, n);
    string op;
    int p, x;
    while (q--) {
        cin >> op;
        if (op[0] == 'Q') {
            cin >> x;
            cout << qry(1, 1, n, x, x) << '\n';
        } else {
            cin >> p >> x;
            add(1, 1, n, p, n, p, x - a[p]);
            a[p] = x;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}