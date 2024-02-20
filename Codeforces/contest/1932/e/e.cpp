#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 4e5 + 5;
int n, m, a[N * 2];
string s;
void MAIN() {
    cin >> n >> s;
    s = " " + s;
    for (int i = 1; i <= m; i++) a[i] = 0;
    for (int i = 1; i <= n; i++) {
        a[n - i + 1] = a[n - i + 2] + s[i] - '0';
    }
    for (int i = 1; ; i++) {
        if (i > n && a[i] == 0) break;
        m = i;
        int x = a[i] / 10; a[i] %= 10;
        a[i + 1] += x;
    }
    while (m > 0 && a[m] == 0) --m;
    for (int i = m; i >= 1; i--) cout << a[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
} 

