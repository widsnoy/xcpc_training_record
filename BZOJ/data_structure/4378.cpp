//能确定的事情只有啊，今天感觉有点寂寞啊
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
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
const int N = 1e6 + 5, M = 1e9;

int n, m, b[N];
vector<int> value;
struct Q {
    int op;
    ll x, y;
} a[N];

struct Tree {
    ll tr[N * 3];
    int M;
    void add(int x, ll v) {
        for (; x <= M; x += x & -x) tr[x] += v;
    }
    ll qry(int x) {
        ll res = 0;
        for (; x; x -= x & -x) res += tr[x];
        return res;
    }
    ll qry(int l, int r) {
        if (l > r) return 0;
        return qry(r) - qry(l - 1);
    }
} t[2];

void MAIN() {
    cin >> n >> m;
    string op;
    for (int i = 1; i <= m; i++) {
        cin >> op >> a[i].x >> a[i].y;
        a[i].op = (op == "Z");
        value.push_back(a[i].x), value.push_back(a[i].y);
    }
    sort(value.begin(), value.end());
    value.erase(unique(value.begin(), value.end()), value.end());
    int siz = value.size();
    t[0].M = t[1].M = siz;
    for (int i = 1; i <= m; i++) {
        int nx = lower_bound(value.begin(), value.end(), a[i].x) - value.begin() + 1;
        int ny = lower_bound(value.begin(), value.end(), a[i].y) - value.begin() + 1;
        if (a[i].op == 0) {
            if (b[a[i].x]) t[0].add(b[a[i].x], -1), t[1].add(b[a[i].x], -value[b[a[i].x] - 1]);
            b[a[i].x] = ny;
            if (b[a[i].x]) t[0].add(b[a[i].x], 1), t[1].add(b[a[i].x], value[b[a[i].x] - 1]);
        } else {
            ll cnt = t[0].qry(ny, siz);
            (a[i].x - cnt) * a[i].y <= t[1].qry(1, ny - 1) ? cout << "TAK\n" : cout << "NIE\n";
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