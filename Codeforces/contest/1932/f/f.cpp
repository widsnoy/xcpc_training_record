#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 1e6 + 5;
int n, m;
pii a[N];
void MAIN() {
    cin >> n >> m;
    vector<int> in[n + 1], out[n + 1];
    for (int i = 1; i <= m; i++) {
        cin >> a[i].fi >> a[i].se;
        in[a[i].fi].push_back(i);
        if (a[i].se < n) out[a[i].se + 1].push_back(i);
    }
    vector<int> dp(n + 1, 0);
    int num = 0;
    multiset<int> st;
    for (int i = 1; i <= n; i++) {
        for (auto x : out[i]) num--, st.erase(st.find(a[x].fi));
        for (auto x : in[i]) num++, st.insert(a[x].fi);
        dp[i] = dp[i - 1];
        if (num == 0) continue;
        int l = *st.begin();
        dp[i] = max(dp[i], dp[l - 1] + num);
    }
    cout << dp[n] << '\n';
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

