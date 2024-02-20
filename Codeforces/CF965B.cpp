#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 1e2 + 5;

int n, k;
string s[N];
void MAIN() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> s[i];
    pii pos; int mx = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) if (s[i][j - 1] == '.')  {
            int len = 0;
            for (int r = j; r <= n; r++) {
                if (s[i][r - 1] == '.') len++;
                else break; 
            }
            if (mx < len) mx = len, pos = {i, j};
            len = 0;
            for (int r = i; r <= n; r++) {
                if (s[r][j - 1] == '.') len++;
                else break;
            }
            if (mx < len) mx = len, pos = {i, j};
        }
    if (mx >= k) cout << pos.fi << ' ' << pos.se << '\n';
    else cout << "0 0\n";
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
} 

