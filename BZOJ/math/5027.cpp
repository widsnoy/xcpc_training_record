//能确定的事情只有啊，今天感觉有点寂寞啊
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define y1 miku
const int mod = 998244353;
const int N = 1e5 + 5;

ll a, b, c, x1, x2, y1, y2;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b) {
        ll d = exgcd(b, a % b, y, x);
        return y -= a / b * x, d;
    } return x = 1, y = 0, a;
}

pll get_up(ll a, ll b, ll x1, ll x2) {
    //x2>=ax+b>=x1 a >= 0
    if (a == 0) return (b >= x1 && b <= x2) ? (pll){-1e18, 1e18} : (pll){1, 0};
    ll L, R;
    ll l = (x1 - b) / a - 3;
    for (L = l; L * a + b < x1; L++);
    ll r = (x2 - b) / a + 3;
    for (R = r; R * a + b > x2; R--);
    return {L, R}; 
}
pll get_dn(ll a, ll b, ll x1, ll x2) {
    //x2>=ax+b>=x1 a <= 0
    if (a == 0) return (b >= x1 && b <= x2) ? (pll){-1e18, 1e18} : (pll){1, 0};
    ll L, R;
    ll l = (x2 - b) / a - 3;
    for (L = l; L * a + b > x2; L++);
    ll r = (x1 - b) / a + 3;
    for (R = r; R * a + b < x1; R--);
    return {L, R}; 
}

void MAIN() {
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
    if (a == 0 && b == 0) return cout << (c == 0) * (y2 - y1 + 1) * (x2 - x1 + 1) << '\n', void();
    ll x, y, d = exgcd(a, b, x, y);
    c = -c;
    if (c % d != 0) return cout << "0\n", void();
    x *= c / d, y *= c / d;
    ll sx = b / d, sy = -a / d;
    //x + k * sx  y + k * sy
    // 0<= 3 - k <= 4 [-1,3] [0,4]
    auto A = (sx > 0 ? get_up(sx, x, x1, x2) : get_dn(sx, x, x1, x2));
    auto B = (sy > 0 ? get_up(sy, y, y1, y2) : get_dn(sy, y, y1, y2));
    A.fi = max(A.fi, B.fi), A.se = min(A.se, B.se);
    cout << max(0ll, A.se - A.fi + 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}