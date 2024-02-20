//复建...o.o
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
const int N = 3e5 + 5;

int n;
vector<int> G[N];
int dp[N], ans;

void dfs(int u, int fa) {
    dp[u] = 1;
    for (int v : G[u]) if (v != fa) {
        dfs(v, u);
        dp[u] = dp[u] * 1ll * dp[v] % mod;
    }
    ans = (ans + dp[u]) % mod;
    dp[u]++;
}

void MAIN() {
    cin >> n;
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans = 1;
    dfs(1, 1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}