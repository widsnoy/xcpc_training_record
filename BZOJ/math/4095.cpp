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
int n, m, q;
int tp[N][32], p[N], rp[N];
void MAIN() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) cin >> p[i], rp[p[i]] = i;
    for (int i = 1; i <= m; i++) tp[i][0] = rp[i] + 1;
    tp[m + 1][0] = m + 1;
    for (int j = 1; j < 32; j++) {
        tp[m + 1][j] = m + 1;
        for (int i = 1; i <= m; i++) tp[i][j] = tp[tp[i][j - 1]][j - 1];
    }
    while (q--) {
        int x;
        cin >> x;
        int y = (x <= m ? n - m : n - x), st = (x <= m ? m - x + 1 : 1);
        for (int k = 0; k < 32; k++) if ((y >> k) & 1) st = tp[st][k];
        if (st <= m) {
            cout << rp[st] << '\n';
        } else {
            int l = 1, r = y, ans = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int now = (x <= m ? m - x + 1 : 1);
                for (int k = 0; k < 32; k++) if ((mid >> k) & 1) now = tp[now][k];
                if (now <= m) now = rp[now];
                if (now == m + 1) r = mid - 1, ans = mid;
                else l = mid + 1;
            }
            cout << y - ans + m + 1 << '\n';
        }
    }   
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T = 1;
    while (T--) MAIN();
    return 0;
} 

