//复建...o.o
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

void MAIN() {
    ll k, x, a;
    cin >> k >> x >> a;
    __int128 sum = 1;
    a--;
    for (int i = 2; i <= x + 1; i++) {
        __int128 y = (sum + k - 2) / (k - 1);
        if (y * (k - 1) == sum) ++y;
        a -= y;
        if (a < 0) return cout << "NO\n", void();
        sum += y;
        //cerr << y << '\n';
    }
    a >= 0 ? cout << "YES\n" : cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}