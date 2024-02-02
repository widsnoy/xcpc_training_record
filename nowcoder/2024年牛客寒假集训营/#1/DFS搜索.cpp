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

void MAIN() {
    int n; string s;
    cin >> n >> s;
    int f[4] = {1, 0, 0, 0}, g[4] = {1, 0, 0, 0};
    string t1 = "0dfs", t2 = "0DFS";
    for (auto x : s) {
        for (int k = 1; k <= 3; k++) {
            if (f[k - 1] && x == t1[k]) f[k] = 1;
            if (g[k - 1] && x == t2[k]) g[k] = 1;
        }
    }
    cout << g[3] << ' ' << f[3] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}