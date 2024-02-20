//会不会写线段树？？？会不会开longlong？？？多测不清零？？？
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
const ll inf = 1e17;

int n, q;
ll a[N];
ll s[N];
ll tr2[N << 2], tag2[N << 2];
#define lc (p << 1)
#define rc ((p << 1) | 1)
#define mid ((l + r) >> 1)
void pushup(int p, int l, int r) {
    tr2[p] = max(tr2[lc], tr2[rc]);
}
void build(int p, int l, int r) {
    tr2[p] = -inf, tag2[p] = 0;
    if (l == r) {
        tr2[p] = s[l] - 2ll * a[l];
        return;
    }
    build(lc, l, mid), build(rc, mid + 1, r);
    pushup(p, l, r);
}
void pushdown(int p, int l, int r) {
    if (tag2[p] != 0) {
        tr2[lc] += tag2[p];
        tag2[lc] += tag2[p];
        tr2[rc] += tag2[p];
        tag2[rc] += tag2[p];
        tag2[p] = 0;
    }
}
void modify2(int p, int l, int r, int L, int R, ll v) {
    if (l > R || r < L) return;
    if (l >= L && r <= R) {
        tr2[p] += v;
        tag2[p] += v;
        return;
    }
    pushdown(p, l, r);
    modify2(lc, l, mid, L, R, v), modify2(rc, mid + 1, r, L, R, v);
    pushup(p, l, r);
}
ll qry2(int p, int l, int r, int L, int R) {
    if (l > R || r < L) return -inf;
    if (l >= L && r <= R) return tr2[p];
    pushdown(p, l, r);
    return max(qry2(lc, l, mid, L, R), qry2(rc, mid + 1, r, L, R));
}
ll sum[N];
void add(int x, ll v) {
    for (; x <= n; x += x & -x) sum[x] += v;
}
ll qry(int x) {
    ll res = 0;
    for (; x; x -= x & -x) res += sum[x];
    return res;
}

void MAIN() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], s[i] = s[i - 1] + a[i], sum[i] = 0;
    }
    for (int i = 1; i <= n; i++) add(i, a[i]);
    build(1, 1, n);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
           // if (l != n) modify1(1, 1, n, l + 1, n, r - a[l]);
           // modify1(1, 1, n, l, l, 2 * (r - a[l]));
            modify2(1, 1, n, l, n, r - a[l]);
            modify2(1, 1, n, l, l, 2ll * (a[l] - r));
            add(l, r - a[l]);
            a[l] = r;
        } else {
            //ll res = qry(r) - qry1(1, 1, n, l, r - 1);
            //cerr << qry2(1, 1, n, l + 1, r) << '\n';
            ll res = qry2(1, 1, n, l + 1, r) - qry(l - 1);
            cout << res << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}