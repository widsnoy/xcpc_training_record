#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i2;
const i2 mod = 1e18;
const int N = 1e5 + 5;
void add(i2 &x, i2 y) {
    ((x += y) >= mod) && (x -= mod);
}
struct M {
    int n, m;
    i2 a[3][3];
    M operator * (const M &q) const {
        M z; z.n = n, z.m = q.m;
        memset(z.a, 0, sizeof z.a);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= q.m; j++) {
                for (int k = 1; k <= m; k++) add(z.a[i][j], a[i][k] * q.a[k][j] % mod);
            }
        }
        return z;
    }
};
int get(i2 b, int k) {
    if (b == 0) return 0;
    --b;
    M e; e.n = e.m = 2; e.a[1][1] = e.a[2][2] = 1, e.a[1][2] = e.a[2][1] = 0;
    M a; a.n = a.m = 2, a.a[1][1] = a.a[1][2] = a.a[2][1] = 1, a.a[2][2] = 0;
    for (; b; b >>= 1, a = a * a) if (b & 1) e = e * a;
    i2 res = e.a[2][1] + e.a[2][2];
    for (int i = 1; i < k; i++) res /= 10;
    return res % 10;
}
int n, a[20];
ll b10[20];
void dfs(int p, i2 k) {
    if (p == n + 1) {
        cout << (unsigned long long)k << '\n';
        for (int i = n; i; i--) assert(get(k, i) == a[i]);
        exit(0);
    }
    i2 bp = b10[p], pb = 6 * bp;
    i2 step = (p == 1 ? 1 :  pb / 10); int t = (p == 1 ? 60 : 10);
    for (int i = 0; i < t; i++) {
        i2 nxt = (k + step * i) % pb;
        if (get(nxt, p) == a[p]) dfs(p + 1, nxt);
    }
}
void MAIN() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    n = s.size();
    for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
    dfs(1, 0);
    cout << "NIE\n";
}    

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T = 1;
    b10[0] = 1;
    for (int i = 1; i <= 18; i++) b10[i] = b10[i - 1] * 10ll;
    //cin >> T;
    while (T--) MAIN();
    return 0;
} 

