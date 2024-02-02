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

int n, q;
ll tc, t[N], s[N];

void MAIN() {
    cin >> n >> q >> tc;
    for (int i = 1; i <= n; i++) cin >> t[i];
    sort(t + 1, t + n + 1);
    for (int i = 1; i <= n; i++) s[i] = t[i] + s[i - 1];
    while (q--) {
        ll m;
        cin >> m;
        int l = 0, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (tc * (n - mid) <= m) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        cout << s[ans] + tc << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}