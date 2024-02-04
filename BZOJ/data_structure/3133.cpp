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
const int N = 1e6 + 5;
const int inf = 1e9;
int n, q, root;
vector<int> G[N];
int mn[N], rk[N], pid[N], clk, faz[N][22];

void pre(int u) {
    mn[u] = u;
    for (int i = 1; i < 22; i++) faz[u][i] = faz[faz[u][i - 1]][i - 1];
    for (int v : G[u]) {
        pre(v);
        mn[u] = min(mn[u], mn[v]);
    }
}
void dfs(int u) {
    sort(G[u].begin(), G[u].end(), [&](int x, int y) {return mn[x] < mn[y];});
    for (int v : G[u]) dfs(v);
    rk[++clk] = u;
    pid[u] = clk;
}
int sum[N << 2], tag[N << 2];
#define lc (p << 1)
#define rc ((p << 1) | 1)
#define mid ((l + r) >> 1)
void pushdown(int p, int l, int r) {
    if (tag[p] == 0) return;
    sum[lc] = mid - l + 1, sum[rc] = r - mid;
    tag[lc] = tag[rc] = tag[p];
    tag[p] = 0;
}
void modify(int p, int l, int r, int L, int R, int v) {
    if (l > R || r < L) return;
    if (l >= L && r <= R) {
        tag[p] = v;
        sum[p] = v * (r - l + 1);
        return;
    }
    pushdown(p, l, r);
    modify(lc, l, mid, L, R, v), modify(rc, mid + 1, r, L, R, v);
    sum[p] = sum[lc] + sum[rc];
}
int qry(int p, int l, int r, int L, int R) {
    if (l > R || r < L) return 0;
    if (l >= L && r <= R) return sum[p];
    pushdown(p, l, r);
    return qry(lc, l, mid, L, R) + qry(rc, mid + 1, r, L, R);
}
#undef mid
int getf(int u, int d) {
    for (int i = 0; i < 22; i++) if ((d >> i) & 1) u = faz[u][i];
    return u;
}

void MAIN() {
    cin >> n >> q;
    for (int i = 1, j; i <= n; i++) {
        cin >> j;
        faz[i][0] = j;
        if (!j) root = i;
        else G[j].push_back(i);
    }
    pre(root); dfs(root);
    int op, num;
    while (q--) {
        cin >> op >> num;
        if (op == 1) {
            int l = 1, r = n, ans = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (mid - qry(1, 1, n, 1, mid) >= num) r = mid - 1, ans = mid;
                else l = mid + 1;
            }
            modify(1, 1, n, 1, ans, 1);
            cout << rk[ans] << '\n';
        } else {
            int l = 1, r = n, ans = 0, pos = 0;
            while (l <= r) {
                int mid = (l + r) >> 1;
                pos = getf(num, mid);
                if (qry(1, 1, n, pid[pos], pid[pos])) l = mid + 1, ans = mid;
                else r = mid - 1;
            }
            pos = getf(num, ans);
            modify(1, 1, n, pid[pos], pid[pos], 0);
            cout << ans << '\n';
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