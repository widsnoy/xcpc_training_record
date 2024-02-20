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
const int N = 1e3 + 5;

ll n, k, a[N], b[N], dp[N];
ll solve() {
    for (int i = 0; i <= n; i++) dp[i] = -1e18;
    ll r = -1e18;
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1] + b[i], b[i]);
        r = max(r, dp[i]);
    }
    return r;
}
void MAIN() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memcpy(b, a, sizeof b);
    if (k == 0) {
        cout << solve();
        return;
    }
    ll ans = -1e18;
    for (int t = 1; t < n; t++) {
        memcpy(b, a, sizeof b);
        swap(b[t], b[t + 1]);
        ans = max(ans, solve());
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}