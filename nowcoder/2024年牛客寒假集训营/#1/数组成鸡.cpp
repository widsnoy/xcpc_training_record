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

int a[N], n, q;

void MAIN() {
    cin >> n >> q;
    set<ll> ans, d;
    ans.insert(0);
    int k = exp(log(1e9) / (double)n) + 3;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = -k; j <= k; j++) d.insert(-a[i] + j);
    }
    for (int di : d) {
        ll r = 1;
        for (int i = 1; i <= n; i++) {
            r *= (di + a[i]);
            if (abs(r) > 1e9 || r == 0) break;
        }
        ans.insert(r);
    }
    while (q--) {
        ll m;
        cin >> m;
        cout << (ans.count(m) ? "Yes" : "No") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}