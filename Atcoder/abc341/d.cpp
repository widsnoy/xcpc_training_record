#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 1e5 + 5;
ll n, m, k;
void MAIN() {
    cin >> n >> m >> k;
    __int128 l = 1, r = 1e16, ans = -1;
    __int128 lc = n * m / gcd(n, m); 
    while (l <= r) {
        __int128 mid = (l + r) >> 1;
        if ((__int128)n * mid / m + mid -  ((__int128)n * mid) / lc * 2 < k) l = mid + 1;
        else ans = mid, r = mid - 1;
    }
    if ((__int128)n * ans / m + ans - ((__int128)n * ans) / lc * 2 == (__int128)k && n * ans % lc) return cout << (ll)(n * ans) << '\n', void();
    swap(n, m);
    l = 1, r = 1e16;
    while (l <= r) {
        __int128 mid = (l + r) >> 1;
        if ((__int128)n * mid / m + mid - ((__int128)n * mid) / lc * 2 < k) l = mid + 1;
        else r = mid - 1, ans = mid;
    }
    if ((__int128)n * ans / m + ans - ((__int128)n * ans) / lc * 2== k && n * ans % lc) return cout << (ll)(n * ans) << '\n', void();
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
} 

