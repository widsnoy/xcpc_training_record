#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 2e5 + 5;
ll s[N], t[N], a[N];
void MAIN() { 
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> s[i] >> t[i];
    for (int i = 1; i < n; i++) {
        ll k = a[i] / s[i];
        a[i + 1] += k * t[i], a[i] -= k * s[i];
    }
    cout << a[n] << '\n';
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

