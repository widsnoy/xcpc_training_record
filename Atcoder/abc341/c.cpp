#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 500 + 5;

int n, m, l;
char s[N][N], a[N];
void MAIN() {
    scanf("%d %d %d %s", &n, &m, &l, a + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (s[i][j] == '.') {
            int x = i, y = j;
            int ok = 1;
            for (int k = 1; k <= l; k++) {
                if (a[k] == 'U') x--;
                if (a[k] == 'D') x++;
                if (a[k] == 'L') y--;
                if (a[k] == 'R') y++;
                if (s[x][y] == '#') {
                    ok = 0;
                    break;
                }   
            }
            ans += ok;
        }
    }
    printf("%d\n", ans);
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

