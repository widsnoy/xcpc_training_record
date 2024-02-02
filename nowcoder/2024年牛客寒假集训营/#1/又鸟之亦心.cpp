//能确定的事情只有啊，今天感觉有点寂寞啊
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
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

int n, x, y;
int a[N];

bool check(int mid, int x) {
    set<int> st;
    if (abs(a[1] - x) <= mid) st.insert(x);
    for (int i = 2; i <= n; i++) {
        if (st.empty()) return false;
        while (!st.empty() && abs(*st.begin() - a[i]) > mid) st.erase(*st.begin());
        while (!st.empty() && abs(*st.rbegin() - a[i]) > mid) st.erase(*st.rbegin());
        if (abs(a[i] - a[i - 1]) <= mid) st.insert(a[i - 1]);
    }
    return !st.empty();
}

void MAIN() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = abs(x - y), r = 1e9, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid, x) || check(mid, y)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}