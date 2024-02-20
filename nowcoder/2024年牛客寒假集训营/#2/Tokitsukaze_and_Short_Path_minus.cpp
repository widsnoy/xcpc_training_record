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
ll a[N], s[N];
ll get(int a, int b) {return a <= b ? s[b] - s[a - 1] : 0;}
void MAIN() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    ll mn = a[1]; mn *= 2;
    ll res = 0;
    for (int i = 1, p = 0; i <= n; i++) {
        res += get(1, p) * 2ll + (i - 1 - p) * 2ll * min(a[i], mn) + min(a[i], mn) * 2ll * (n - i);
        if (a[i] <= mn) ++p;
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