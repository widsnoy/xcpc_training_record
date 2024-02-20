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
int dp[N];
vector<int> G[N], dep[N];
void MAIN() {
    int a, b;
    cin >> a >> b;
    int n = a + b;
    if (!((a & 1) && !(b & 1))) return cout << "No\n", void();
    if (b == 0 && a > 1) return cout << "No\n", void();
    dp[1] = 1;
    a--;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] * 2;
        if (i & 1) {
            dp[i] = min(dp[i], a), a -= dp[i];
        } else dp[i] = min(dp[i], b), b -= dp[i];
        if (dp[i] == 0) break;
    }
    if (a > 0 || b > 0) return cout << "No\n", void();
    for (int i = 1; i <= n; i++) G[i].clear(), dep[i].clear();
    dep[1].push_back(1);
    int tot = 1;
    for (int i = 2; i <= n; i++) {
        if (dp[i] == 0) break;
        for (int j = 1; j <= dp[i]; j++) {
            dep[i].push_back(++tot);
            G[dep[i - 1][(j - 1) / 2]].push_back(tot);
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        //cerr << i << ' ' << dp[i] << '\n';
        if (G[i].empty()) cout << "-1 -1\n";
        else cout << G[i][0] << ' ' << G[i][1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}