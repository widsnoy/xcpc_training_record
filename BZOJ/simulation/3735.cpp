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

ll n, k, a[N], ini[N];

void MAIN() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> a[i], ini[i] = i;
    ll l = 0, r = 1e18, ans = -1;
    auto check = [&](ll mid) {
        ll res = 0;
        for (int i = 1; i <= k; i++) res += mid / a[i]; 
        return res <= n;
    };
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    ll dis = 1e18, re = 0;
    for (int i = 1; i <= k; i++) {
        dis = min(dis, max((ans / a[i] - 1) * a[i], 0ll));
    }
    for (int i = 1; i <= k; i++) re += dis / a[i], q.push({dis / a[i] * a[i], i});
    while (!q.empty() && re < n) {
        auto [d, u] = q.top();
        q.pop();
        ini[u] = ++re;
        q.push({d + a[u], u});
    }
    for (int i = 1; i <= k; i++) cout << ini[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}