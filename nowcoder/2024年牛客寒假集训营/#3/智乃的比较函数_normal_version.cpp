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
int n, m, a[5];
struct E {int u, v, w;} e[55];
bool check() {
    for (int i = 1; i <= m; i++) {
        auto [u, v, w] = e[i];
        if (w == 0) {
            if (a[u] < a[v]) return 0;
        } else if (a[u] >= a[v]) return 0;
    }
    return 1;
}
void MAIN() {
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for (a[1] = 0; a[1] <= 3; a[1]++) {
        for (a[2] = 0; a[2] <= 3; a[2]++) {
            for (a[3] = 0; a[3] <= 3; a[3]++) {
                if (check()) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}