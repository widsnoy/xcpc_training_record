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
const int N = 10 + 5;

int n, m, a[N], b[N], p[N], ans;
pii e[N];

void dfs(int x) {
    if (x == m + 1) {
        for (int i = 1; i <= n; i++) b[i] = a[i];
        for (int i = 1; i <= m; i++) {
            if (p[i] == 1) b[e[i].se] += 3;
            if (p[i] == 2) b[e[i].fi] += 3;
            if (p[i] == 3) b[e[i].se]++, b[e[i].fi]++;
        }
        //for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
        int rk = 1;
        for (int i = 2; i <= n; i++) if (b[i] > b[1]) rk++;
        ans = min(ans, rk);
        return;
    }
    for (int i = 1; i < 4; i++) {
        p[x] = i;
        dfs(x + 1);
    }
}

void MAIN() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> e[i].fi >> e[i].se;
    ans = n + 1;
    dfs(1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}