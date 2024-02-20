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
int n, m;
ll a[N], pre[2][N], suf[2][N];
void MAIN() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int cur = 1;
    a[n + 1] = m;
    for (int i = 0; i <= n; i++) {
        pre[cur][i] = a[i + 1] - a[i];
        suf[cur][i] = pre[cur][i];
        cur ^= 1;
    }
    for (int k = 0; k < 2; k++) {
        for (int i = 1; i <= n + 1; i++) pre[k][i] += pre[k][i - 1];
        for (int i = n; i >= 0; i--) suf[k][i] += suf[k][i + 1];
    }
    cur = 0;
    ll ans = suf[1][0];
    for (int i = 0; i <= n; i++) {
        ans = max(ans, pre[1][i - 1] + suf[0][i + 1] + a[i + 1] - a[i] - 1); 
        cur ^= 1;
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