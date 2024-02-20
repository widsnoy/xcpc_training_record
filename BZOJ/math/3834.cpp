#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 1e5 + 5;

void MAIN() {
    int a, b, c, d;
    vector<pii> v[2];
    auto get = [](int a, int b, vector<pii> &v) {
        for (int i = 1; i <= b / i; i++) {
            int l = (a + i - 1) / i, r = b / i;
            if (l > r) continue;
            v.push_back({i, i}), v.push_back({l, r});
        }
    };
    cin >> a >> b >> c >> d;
    get(a, b, v[0]), get(c, d, v[1]);
    for (int k = 0; k < 2; k++) sort(v[k].begin(), v[k].end());
    auto calc = [&]() {
        int res = 0, p = 0, mx = 0;
        for (int i = 0; i < v[0].size(); i++) {
            while (p < v[1].size() && v[1][p].fi <= v[0][i].fi) mx = max(mx, v[1][p++].se);
            if (mx >= v[0][i].fi) res = max(res, min(mx, v[0][i].se));
        }
        return res;
    };
    int ans = calc();
    swap(v[0], v[1]);
    ans = max(calc(), ans);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
} 

