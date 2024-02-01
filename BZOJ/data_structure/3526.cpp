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
const int N = 200000 + 5;

int n, m;
int a[N][2];

struct node {
    int lp, rp, cb[2][2];
    node operator + (const node &q) const {
        if (q.lp == 0) return *this;
        if (this->lp == 0) return q;
        node z;
        memset(z.cb, 0, sizeof z.cb);
        z.lp = lp, z.rp = q.rp;
        for (int i1 = 0; i1 < 2; i1++) for (int j1 = 0; j1 < 2; j1++) {
            for (int i2 = 0; i2 < 2; i2++) for (int j2 = 0; j2 < 2; j2++) {
                if (!cb[i1][j1] || !q.cb[i2][j2] || a[rp][j1] > a[q.lp][i2]) continue;
                z.cb[i1][j2] = 1;
            }
        }
        return z;
    }
} tr[N << 2];
#define lc (p << 1)
#define rc ((p << 1) | 1)
#define mid ((l + r) >> 1)
void build(int p, int l, int r) {
    if (l == r) {
        tr[p].lp = l, tr[p].rp = r;
        for (int i = 0; i < 2; i++)  tr[p].cb[i][i] = 1;
        return;
    }
    build(lc, l, mid), build(rc, mid + 1, r);
    tr[p] = tr[lc] + tr[rc];
}
void modify(int p, int l, int r, int pos) {
    if (l == r) return;
    if (pos <= mid) modify(lc, l, mid, pos);
    else modify(rc, mid + 1, r, pos);
    tr[p] = tr[lc] + tr[rc];
}
bool query() {
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) if (tr[1].cb[i][j] == 1) return 1;
    return 0;
}

void MAIN() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];
    build(1, 1, n);
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        swap(a[u], a[v]);
        modify(1, 1, n, u), modify(1, 1, n, v);
        query() ? cout << "TAK\n" : cout << "NIE\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}