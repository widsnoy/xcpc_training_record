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
int v[N], w[N];
ll get(int x) {
    ll res = 0;
    for (int i = 1; i <= n; i++) if ((w[i] & x) == w[i]) res += v[i];
    return res;
}
void MAIN() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    ll ans = get(m);
    for (int k = 30; k >= 0; k--) if ((m >> k) & 1) {
        int x = (m ^ (1 << k)) | ((1 << k) - 1);
        ans = max(get(x), ans);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}