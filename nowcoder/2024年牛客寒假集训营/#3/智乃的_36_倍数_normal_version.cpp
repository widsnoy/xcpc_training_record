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
const int N = 1e5 + 5;
ll mp[20][40];
int n; ll a[N], p10[20];
void MAIN() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int y = a[i] % 36;
        int x = 0;
        while (a[i]) a[i] /= 10, x++;
        mp[x][y]++;
    }
    ll ans = 0;
    for (int la = 1; la <= 19; la++) {
        for (int ra = 0; ra <= 35; ra++) {
            for (int lb = 1; lb <= 19; lb++) {
                for (int rb = 0; rb <= 35; rb++) {
                    int x = mp[la][ra], y = mp[lb][rb];
                    if ((ra * 1ll * p10[lb] % 36 + rb) % 36 != 0) continue;
                    ans += x * 1ll * y;
                    if (la == lb && ra == rb) ans -= x;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    p10[0] =1;
    for (int i = 1; i < 20; i++) p10[i] = p10[i - 1] * 10 % 36;
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}