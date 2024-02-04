//能确定的事情只有啊，今天感觉有点寂寞啊
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
// using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 1e5 + 5;

int n;
ll A, R, M;
int a[N];
void MAIN() {
    cin >> n >> A >> R >> M;
    M = min(M, A + R);
    ll f = 0, g = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], g += a[i];
    sort(a + 1, a + n + 1);
    ll ans = 1e18;
    for (int i = 1; i <= n; i++) {
        g -= a[i];
        ll x = (i - 1) * 1ll * a[i] - f, y = g - (n - i) * 1ll * a[i];
        if (x >= y) {
            ans = min(ans, (x - y) * A + y * M);
        } else ans = min(ans, (y - x) * R + x * M);
        f += a[i];
    }
    auto get = [&](ll b) {
        ll x = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < b) x += b - a[i];
            else y += a[i] - b;
        }
        if (x >= y) {
            ans = min(ans, (x - y) * A + y * M);
        } else ans = min(ans, (y - x) * R + x * M);
    };
    get(f / n), get(f / n + 1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}