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

int n;
ll a[N];

void MAIN() {
    cin >> n;
    ll g = 0, f = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], g += a[i];
    ll res = 0;
    for (int i = 1; i <= n; i++) res += 2ll * (n - 1) * a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        f += a[i], g -= a[i];
        ll x = i * 1ll * a[i] - f, y = g - (n - i) * 1ll * a[i];
        res += x + y;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}