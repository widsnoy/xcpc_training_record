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
int n, p[N];
void MAIN() {
    cin >> n;
    int x = 0;
    for (int i = 1; i <= n; i += 2) p[i] = ++x;
    for (int i = 2; i <= n; i += 2) p[i] = ++x;
    for (int i = 1; i <= n; i++) cout << p[i] << " \n"[i == n];
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

