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
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 1e5 + 5;
int n;
pii a[N];
vector<pii> tr[N];
void insert(int x, int y) {
    for (int i = x; i; i -= i & -i) {
        while (!tr[i].empty() && tr[i].back().se >= x) tr[i].pop_back();
        tr[i].push_back({y, x});
    }
}
int qry(int x, int y) {
    int res = 0, lst = 2000000005;
    for (; x <= n; x += x & -x) {
        if (tr[x].empty()) continue;
        int l = 0, r = tr[x].size() - 1, pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (tr[x][mid].fi < lst) r = mid - 1, pos = mid;
            else l = mid + 1;
        }
        if (pos == -1) continue;
        res += tr[x].size() - pos;
        lst = tr[x].back().fi;
    }
    return res;
}

ll solve() {
    for (int i = 1; i <= n; i++) tr[i].clear();
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += qry(a[i].fi, a[i].se);
       // cerr << a[i].fi - 1 << ' ' << a[i].se << ' ' << qry(a[i].fi, a[i].se) << '\n';
        insert(a[i].fi, a[i].se);
    }
    return ans;
}
void MAIN() {
    cin >> n;
    vector<int> vec;
    map<int, int> rx, ry;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se, vec.push_back(a[i].fi);
        rx[a[i].fi]++, ry[a[i].se]++;
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    auto cmp = [](pii x, pii y) {return x.se > y.se || (x.se == y.se && x.fi > y.fi);};
    for (int i = 1; i <= n; i++) a[i].fi = lower_bound(vec.begin(), vec.end(), a[i].fi) - vec.begin() + 1;
    sort(a + 1, a + n + 1, cmp);
    ll ans = solve();
    for (int i = 1; i <= n; i++) a[i].se = -a[i].se;
    sort(a + 1, a + n + 1, cmp);
    ans += solve();
    for (auto [x, r] : rx) ans -= r - 1;
    for (auto [x, r] : ry) ans -= r - 1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}