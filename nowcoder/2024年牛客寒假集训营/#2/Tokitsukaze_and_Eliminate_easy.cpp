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
const int N = 2e5 + 5;
const int inf = 1e9;

int n, a[N];
int tr[N << 2];
#define lc (p << 1)
#define rc ((p << 1) | 1)
#define mid ((l + r) >> 1)
void build(int p, int l, int r) {
    tr[p] = inf;
    if (l == r) return;
    tr[p] = max(tr[lc], tr[rc]);
}
void insert(int p, int l, int r, int pos, int v) {
    if (l == r) {
        tr[p] = v;
        return;
    }
    if (pos <= mid) insert(lc, l, mid, pos, v);
    else insert(rc, mid + 1, r, pos, v);
    tr[p] = max(tr[lc], tr[rc]);
}
int qry(int p, int l, int r, int L, int R) {
    if (l > R || r < L) return inf;
    if (l >= L && r <= R) return tr[p];
    return min(qry(lc, l, mid, L, R), qry(rc, mid + 1, r, L, R));
}

void MAIN() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 0, n);
    reverse(a + 1, a + n + 1);
    vector<int> pos[n + 1];
    vector<int> p(n + 1, -1);
    insert(1, 0, n, 0, 0);
    for (int i = 1; i <= n; i++) pos[a[i]].push_back(i);
    for (int i = 1; i <= n; ++i) {
        ++p[a[i]];
        if (p[a[i]] == 0) insert(1, 0, n, i, 1);
        else {
            int lsp = pos[a[i]][p[a[i]] - 1];
            int res = qry(1, 0, n, lsp, i - 1);
            insert(1, 0, n, i, res + 1);
        }
    }
    cout << qry(1, 0, n, n, n) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}