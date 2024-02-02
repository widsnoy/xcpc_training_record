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

int get(map<int, int> &L, map<int, int> &R) {
    int res = 0;
    if (R.empty()) res = 2;
    else res = 1;
    for (auto [x, v] : R) {
        //cerr << "R " << x << ' ' << v << '\n';
        if (R.count(x + 1) && (R[x + 1] ^ v) == 3) {
            res = 0;
            break;
        }
        if (v == 3) {
            res = 0;
            break;
        }
    }
    int re = 0;
    if (L.empty()) re = 2;
    else re = 1;
    for (auto [x, v] : L) {
        //cerr << "L " << x << ' ' << v << '\n';
        if (L.count(x + 1) && (L[x + 1] ^ v) == 3) {
            re = 0;
            break;
        }
        if (v == 3) {
            re = 0;
            break;
        }
    }
    return re + res;
}

void MAIN() {
    int n;
    map<int, int> L, R;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if (y > 0) R[y] |= (1 << (x - 1));
        else if (y < 0) L[-y] |= (1 << (x - 1));
        else R[y] |= (1 << (x - 1)), L[y] |= (1 << (x - 1));
    }
    int ans = get(L, R); 
    L[0] = 2, R[0] = 2;
    ans = min(ans, get(L, R) + 1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}