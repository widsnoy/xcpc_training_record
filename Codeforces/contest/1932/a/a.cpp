#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 50 + 5;
int n, dp[N];
string s;
void MAIN() {
    cin >> n >> s;
    s = " " + s;
    memset(dp, -1, sizeof dp);
    if (s[1] != '*') dp[1] = s[1] == '@';
    if (dp[1] != -1 && s[2] != '*') dp[2] = dp[1] + (s[2] == '@');
    for (int i = 3; i <= n; i++) if (s[i] != '*') {
        if (dp[i - 1] != -1) dp[i] = max(dp[i], dp[i - 1] + (s[i] == '@'));
        if (dp[i - 2] != -1) dp[i] = max(dp[i], dp[i - 2] + (s[i] == '@'));
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] != -1) ans = max(dp[i], ans); 
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
} 

