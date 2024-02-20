#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 5e6 + 5;
int pri[N], pcnt, vis[N];
void pre() {
    for (int i = 2; i < N; i++) {
        if (vis[i] == 0) pri[++pcnt] = i;
        for (int j = 1; j <= pcnt && i * 1ll * pri[j] < N; j++) {
            int v = i * pri[j];
            vis[v] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}
ull fpow(ull a, int b) {
    ull res = 1;
    for (; b; b >>= 1, a = a * a) if (b & 1) res = res * a;
    return res;
}
void MAIN() {
    pre();
    ll n, k;
    cin >> n >> k;
    vector<int> lis;
    for (int i = 2; i <= pcnt; i++) {
        if (pri[i] <= 63) lis.push_back(pri[i]);
        else break;
    }
    vector<ull> p;
    ull l = sqrt(n), r = l + 3000000;
    vector<int> vis(r - l + 2, 0);
    for (int i = 1; i <= pcnt; i++) {
        for (ull j = max(2ull, (l + pri[i] - 1) / pri[i]) * pri[i]; j <= r; j += pri[i]) {
            vis[j - l] = 1;
        }
    }
    for (int i = 0; i < r - l + 2; i++) if (vis[i] == 0 && (i + l) * 1ull * (i + l) > n) p.push_back((i + l) * 1ull * (i + l));
    for (int x : lis) {
        for (int i = 1; i <= pcnt && pri[i] <= 2000000; i++) {
            if (x * 1ull * log(pri[i]) > log(ULLONG_MAX)) break;
            if (fpow(pri[i], x) > n) p.push_back(fpow(pri[i], x));
        } 
    }
    sort(p.begin(), p.end());
    cout << p[k - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T = 1;
    while (T--) MAIN();
    return 0;
} 

