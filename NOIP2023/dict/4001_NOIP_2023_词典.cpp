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
const int N = 3005;

int a[N], b[N], n, m, f[N], g[N];

void MAIN() {
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        b[i] = 27;
        for (auto ch : s) a[i] = max(ch - 'a' + 1, a[i]), b[i] = min(ch - 'a' + 1, b[i]);
    }
    f[1] = a[1];
    for (int i = 2; i <= n; i++) f[i] = min(a[i], f[i - 1]);
    g[n] = a[n];
    for (int i = n - 1; i >= 1; i--) g[i] = min(g[i + 1], a[i]);
    for (int i = 1; i <= n; i++) {
        if ((i > 1 && b[i] >= f[i - 1]) || (i < n && b[i] >= g[i + 1])) cout << '0';
        else cout << '1';
    }
}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}