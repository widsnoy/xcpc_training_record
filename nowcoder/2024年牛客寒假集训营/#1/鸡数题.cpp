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
const int N = 1e5 + 5;

int fpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b) {
        ll d = exgcd(b, a % b, y, x);
        return y -= a / b * x, d;
    } else return x = 1, y = 0, a;
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
int getphi(int x) {
    int res = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            x /= i;
            res *= (i - 1);
            while (x % i == 0) {
                x /= i;
                res *= i;
            }
        }
    }
    if (x > 1) res *= (x - 1);
    return res;
}
int prime[N], pcnt;
bool isp[N];
int get_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!isp[i]) prime[++pcnt] = i;
        for (int j = 1; j <= pcnt && i * prime[j] <= n; j++) {
            isp[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
} 
int n, m;
void MAIN() {
    cin >> n >> m;
    if (m > n) return cout << "0\n", void();
    init_binom(n);
    int r = 0;
    for (int i = 0; i <= m; i++) {
        if ((m - i) & 1) r += mod - binom(m, i) * 1ll * fpow(i, n) % mod;
        else r += binom(m, i) * 1ll * fpow(i, n) % mod;
        r %= mod;
    }
    cout << r * 1ll * ifac[m] % mod << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}