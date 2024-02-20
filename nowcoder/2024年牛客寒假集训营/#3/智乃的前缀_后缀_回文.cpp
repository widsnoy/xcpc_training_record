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
const int N = 4e5 + 5;
int n, m;
char s[N], t[N], st[2 * N], tt[N * 4];
int k[N * 2], d[N * 4];
void init() {
    for (int i = 2; i <= n + m; i++) {
        int j = k[i - 1];
        while (j != 0 && st[i] != st[j + 1]) j = k[j];
        if (st[i] == st[j + 1]) k[i] = j + 1;
        else k[i] = 0;
    }
    for (int i = 1; i <= n + m; i++) tt[i * 2] = st[i], tt[i * 2 - 1] = '#';
    tt[(n + m) * 2 + 1] = '#';
    int len = (n + m) * 2 + 1;
    for (int i = 1, l = 0, r = 0; i <= len; i++) {
        int kk = i <= r ? min(d[r - i + l], r - i + 1) : 1;
        while (i + kk <= len && i - kk >= 1 && tt[i + kk] == tt[i - kk]) kk++;
        d[i] = kk--;
        if (i + kk > r) r = i + kk, l = i - kk;
    }
}
bool check(int x) {
    int y = x / 2 + 1;
    return d[2 * y - !(x & 1)] / 2 >= y - !(x & 1);
}
vector<int> v1, v2;
void MAIN() {
    scanf("%d %d", &n, &m);
    scanf("%s %s", s + 1, t + 1);
    for (int i = 1; i <= n; i++) st[i] = s[i];
    st[++n] = '*';
    for (int i = 1; i <= m; i++) st[n + i] = t[i];
    init();
    int now = k[n + m];
    while (now) {
       // cerr << now << ' ' << check(now) << '\n';
        if (check(now)) v1.push_back(now);
        now = k[now];
    }
    --n;
    for (int i = 1; i <= m; i++) st[i] = t[i];
    st[++m] = '*';
    for (int i = 1; i <= n; i++) st[m + i] = s[i];
    init();
    now = k[n + m];
    --m;
    while (now) {
        if (check(now)) v2.push_back(now);
        now = k[now];
    }
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    int ans = -1;
    if (v1.empty() || v2.empty()) return cout << "-1\n", void();
    for (int x : v1) {
        int lim = min(n - x, m - x);
        auto it = upper_bound(v2.begin(), v2.end(), lim);
        if (it == v2.begin()) continue;
        it = prev(it);
        ans = max(ans, x + *it);
    }
    cout << ans * 2 << '\n';
}

int main() {
    int T = 1;
    while (T--) MAIN();
    return 0;
}