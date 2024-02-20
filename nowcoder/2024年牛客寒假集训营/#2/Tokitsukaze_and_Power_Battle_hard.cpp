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
const int N = 5e5 + 5;
const ll inf = 1e15;
int n, q, a[N];
struct node {
    ll len, sum, lx, rm, r, lr, rr, sr;
    node operator + (const node &q) const {
        if (len == 0) return q;
        if (q.len == 0) return *this;
        node z;
        z.len = len + q.len;
        z.sum = sum + q.sum;
        z.lx = min({lx, sum + q.lx});
        z.rm = max({q.rm, q.sum + rm});
        if (len == 1 && q.len == 1) {
            z.r = sum - q.sum;
            z.lr = sum - q.sum;
            z.rr = sum - q.sum;
            z.sr = sum - q.sum;
        } else if (len > 1 && q.len > 1) {
            z.lr = max({lr, sum + q.lr, sr - q.lx, sum - q.lx});
            z.rr = max({q.rr, q.sr + rm, rr - q.sum, rm - q.sum});
            z.r = max({r, q.r, rr - q.lx, rm - q.lx, rm + q.lr});
            z.sr = max({sr - q.sum, sum + q.sr, sum - q.sum});
        } else if (len == 1) {
            z.lr = max({sum + q.lr, sum - q.lx});
            z.rr = max({q.rr, q.sr + rm, rm - q.sum});
            z.r = max({q.r, rm - q.lx, rm + q.lr});
            z.sr = max({sum + q.sr, sum - q.sum});
        } else {
            z.lr = max({lr, sum - q.lx, sr - q.lx});
            z.rr = max({rr - q.sum, rm - q.sum});
            z.r = max({r, rr - q.lx, rm - q.lx});
            z.sr = max({sr - q.sum, sum - q.sum});
        }
        return z;
    }
} tr[N << 2];
#define lc (p << 1)
#define rc ((p << 1) | 1)
#define mid ((l + r) >> 1)
void build(int p, int l, int r) {
    if (l == r) {
        tr[p] = {1, a[l], a[l], a[l], -inf, -inf, -inf, -inf};
        return;
    }
    build(lc, l, mid), build(rc, mid + 1, r);
    tr[p] = tr[lc] + tr[rc];
}
void modify(int p, int l, int r, int pos, int v) {
    if (l == r) {
        tr[p] = {1, v, v, v, -inf, -inf, -inf, -inf};
        return;
    }
    if (pos <= mid) modify(lc, l, mid, pos, v);
    else modify(rc, mid + 1, r, pos, v);
    tr[p] = tr[lc] + tr[rc];
}
node query(int p, int l, int r, int L, int R) {
    if (l > R || r < L) return (node){0, 0, 0, 0, 0, 0, 0, 0};
    if (l >= L && r <= R) return tr[p];
    return query(lc, l, mid, L, R) + query(rc, mid + 1, r, L, R);
} 

void MAIN() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) modify(1, 1, n, l, r);
        else cout << query(1, 1, n, l, r).r << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}