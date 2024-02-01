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
const int N = 1000000 + 5;

int n, m;
int a[N], b[N], w[N], poi[N];
vector<int> pos[N];
#define lc (p << 1)
#define rc ((p << 1) | 1)
#define mid ((l + r) >> 1)
struct node {
    ll lm, rm, sum;
    node operator + (const node &q) const {
        node z;
        z.lm = max(lm, sum + q.lm);
        z.rm = max(q.rm, q.sum + rm);
        z.sum = sum + q.sum;
        return z;
    }
} tr[N << 2];
void modify(int p, int l, int r, int pos) {
    if (l == r) {
        tr[p] = {max(0, b[pos]), max(0, b[pos]), b[pos]};
        return;
    }
    if (pos <= mid) modify(lc, l, mid, pos);
    else modify(rc, mid + 1, r, pos);
    tr[p] = tr[lc] + tr[rc];
}
node qry(int p, int l, int r, int L, int R) {
    if (l > R || r < L) return {0, 0, 0};
    if (l >= L && r <= R) return tr[p];
    return qry(lc, l, mid, L, R) + qry(rc, mid + 1, r, L, R);
}

void MAIN() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]].push_back(i);
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= m; i++) if (!pos[i].empty()) {
        b[pos[i][0]] = w[i];
        for (int j = 1; j < pos[i].size(); j++) b[pos[i][j]] = (j == 1 ? -w[i] : 0);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) modify(1, 1, n, i);
    for (int i = 1; i <= n; i++) {
        ans = max(ans, qry(1, 1, n, i, n).lm);
        ++poi[a[i]];
        if (poi[a[i]] < pos[a[i]].size()) b[pos[a[i]][poi[a[i]]]] = w[a[i]], modify(1, 1, n, pos[a[i]][poi[a[i]]]);
        if (poi[a[i]] + 1 < pos[a[i]].size()) b[pos[a[i]][poi[a[i]] + 1]] = -w[a[i]], modify(1, 1, n, pos[a[i]][poi[a[i]] + 1]);
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