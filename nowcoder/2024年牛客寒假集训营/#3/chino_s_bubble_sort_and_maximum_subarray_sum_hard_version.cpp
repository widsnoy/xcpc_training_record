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
const int N = 1000 + 5;
const ll inf = 1e18;

ll s[N], a[N];
int n, m;
ll dp[2][105][105], pre[N][105], suf[N][105];
void init(int cur) {
    for (int i = 0; i <= m; i++) for (int j = 0; j <= m; j++) dp[cur][i][j] = -inf;
}
void solve(int tp) {
    int cur = 0;
    init(0), init(1);
    dp[cur][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        cur ^= 1; 
        init(cur);
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= m; k++) {
                if (k > 0) dp[cur][j][k] = max(dp[cur][j][k], dp[cur ^ 1][j][k - 1] + a[i]);
                if (j >= k) dp[cur][j][k] = max(dp[cur][j][k], dp[cur ^ 1][j - k][k]);
               // if (tp == 1 && i == 5) cerr << "* " << j << ' ' << k << ' ' << dp[cur][j][k] << '\n';
                if (tp == 1) pre[i][j] = max(pre[i][j], dp[cur][j][k] - s[i]);
                else suf[n - i + 1][j] = max(suf[n - i + 1][j], dp[cur][j][k] + s[n - i]);
            }
        }
    }
}
void MAIN() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (*max_element(a + 1, a + n + 1) < 0) return cout << *max_element(a + 1, a + n + 1) << '\n', void();
    if (n == 2) {
        cout << max(*max_element(a + 1, a + n + 1), a[1] + a[2]);
        return;
    }
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) suf[i][j] = pre[i][j] = -inf;
    }
    solve(1);
    reverse(a + 1, a + n + 1);
    solve(233);
    ll ans = -inf;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            //cerr << i << ' ' << j << ' ' << pre[i][j] << ' ' << suf[i][j] <<'\n';
            pre[i][j] = max(pre[i - 1][j], pre[i][j]);
            suf[n - i][j] = max(suf[n - i][j], suf[n - i + 1][j]);
        }
    }
    for (int i = 2; i < n; i++) {
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= j; k++) ans = max(ans, pre[i][k] + suf[i + 1][j - k]);
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