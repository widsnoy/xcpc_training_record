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
const int N = 1e6 + 5;

int n, p, q, r, a[N], f[N], g[N], t[N];
int mp[N];

int fpow(int a, int b, int mod) {
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod) if (b & 1) res = res * 1ll * a % mod;
    return res;
}

void MAIN() {
    cin >> n >> p >> q >> r;
    string s;
    cin >> s;
    int iv = fpow(10, q - 2, q), rr = iv;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
        f[i] = (f[i - 1] * 10 + a[i]) % p;
        t[i] = (t[i - 1] + a[i] * 1ll * iv % q) % q;
        iv = iv * 1ll * rr % q;
    }
    int b = 1;
    for (int i = n; i >= 1; i--) {
        g[i] = (g[i + 1] + a[i] * 1ll * b % r) % r;
        b = b * 10 % r; 
    }
    ll ans = 0;
    for (int i = 2; i < n; i++) {
        if (g[i + 1] == 0 && (a[i + 1] != 0 || i == n - 1)) {
            ans += mp[t[i]];
            if (a[i] == 0 && f[i - 1] == 0) ans++; 
        }
        if (f[i] == 0 && a[i + 1] != 0) mp[t[i]]++;
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