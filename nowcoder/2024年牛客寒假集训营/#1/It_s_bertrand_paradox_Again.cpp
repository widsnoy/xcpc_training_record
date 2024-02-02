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
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 1e5 + 5;

ll rand(ll a, ll b) {
    return rng() % (b - a + 1) + a;
}
bool check(ll x, ll y, ll r) {
    if (x - r < -100 || y - r < -100 || x + r > 100 || y + r > 100) return 0;
    return 1;
}

void MAIN() {
    int n = 1e5;
    cin >> n;
    ll x, y, r, s0 = 0, s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> r;
        // x = rand(-99, 99), y = rand(-99, 99);
        // r = rand(1, 100);
        // while (!check(x, y, r)) r = rand(1, 100);
        s0 += x, s1 += y, s2 += r;
    }
    s0 /= n, s1 /= n, s2 /= n;
    //cout << s0 << ' ' << s1 << ' ' << s2 << '\n';
    if (s0 == 0 && s1 == 0 && s2 == 17) cout << "bit-noob\n";
    else cout << "buaa-noob\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}