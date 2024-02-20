#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 1000 + 5;
int n, m, a, b;
char s[N][N], t[N][N];
int vis[N][N];
int get(int i, int j) {
    if (i > n || j > m || i < 1 || j < 1 || s[i][j] == '.' || vis[i][j]) return 0;
    return 1;
} 
void MAIN() {
    memset(vis, 0, sizeof vis);
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= a; i++) scanf("%s", t[i] + 1);
    vector<pii> ve;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) if (t[i][j] == 'x') ve.push_back({i, j});
    }
    if (!ve.empty()) {
        auto [sx, sy] = ve[0];
        for (int i = 0; i < ve.size(); i++) ve[i].fi -= sx - 1, ve[i].se -= sy - 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (get(i, j)) {
            for (auto [x, y] : ve) {
                cout << x << ' ' << y << '\n';
                if (!get(i + x - 1, j + y - 1)) return puts("NIE"), void();
                vis[i + x - 1][j + y - 1] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (!vis[i][j] && s[i][j] == 'x') return puts("NIE"), void();
    }
    puts("TAK");   
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T = 1;
    scanf("%d", &T);
    while (T--) MAIN();
    return 0;
} 

