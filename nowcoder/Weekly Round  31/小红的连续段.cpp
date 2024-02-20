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

const int mod = 1e9 + 7;
const int N = 1000 + 5;

int fpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}
int getinv(int v) {
    return fpow(v, mod - 2);
    // ll x, y;
    // exgcd(v, mod, x, y);
    // return (x % mod + mod) % mod;
}
int fac[N], ifac[N];
void init_binom(int n) {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * 1ll * i % mod;
    ifac[n] = getinv(fac[n]);
    for (int i = n; i > 1; i--) ifac[i - 1] = ifac[i] * 1ll * i % mod;
}
int binom(int a, int b) {
    if (b < 0 || a < 0 || b > a) return 0;
    return fac[a] * 1ll * ifac[b] % mod * ifac[a - b] % mod; 
}

int get(int x, int y, int n, int m) {
    return binom(x - 1, n - 1) * 1ll * binom(y - 1, m - 1) % mod;
}

void MAIN() {
    init_binom(1000);
    int x, y;
    cin >> x >> y;
    int mx = min(x, y) * 2 + (max(x, y) - min(x, y) != 0);
    cout << 0 << '\n';
    for (int k = 2; k <= mx; k++) {
        int res = 0;
        int n = k / 2, m = k / 2;
        if (k > n + m) {
            if (x - n > 0) res = (res + get(x, y, n + 1, m)) % mod;
            if (y - m > 0) res = (res + get(x, y, n, m + 1)) % mod;
        } else res = get(x, y, n, m) * 2 % mod;
        cout << res << '\n';
    }
    for (int i = mx + 1; i <= x + y; i++) cout << 0 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}