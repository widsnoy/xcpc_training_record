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
const int N = 200 + 5, M = 200 * 200;

int n, a[N], dp[N][M * 2 + 500];

void MAIN() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    if (sum & 1) return cout << "-1\n", void();
    sum /= 2;
    memset(dp, 0x3f, sizeof dp);
    dp[0][M] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = n * -200; j <= n * 200; j++) {
            dp[i][j + M] = min(dp[i - 1][j + M], dp[i - 1][j - a[i] + M] + 1);
        }
    }
    if (dp[n][sum + M] == 0x3f3f3f3f) dp[n][sum + M] = -1;
    cout << dp[n][sum + M] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}