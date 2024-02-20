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

map<int, int> nxt, pre;

void MAIN() {
    int n, cnt = 0;
    cin >> n;
    while (n--) {
        int op, x, y;
        cin >> op >> x;
        if (op == 1) {
            cin >> y;
            ++cnt;
            if (!nxt.count(y)) {
                nxt[y] = x;
                nxt[x] = 0;
                pre[x] = y;
                continue;
            }
            nxt[x] = nxt[y];
            nxt[y] = x;
            pre[nxt[x]] = x;
            pre[x] = y;
        } else {
            --cnt;
            nxt[pre[x]] = nxt[x];
            pre[nxt[x]] = pre[x];
        }
    }
    int u = nxt[0];
    cout << cnt << '\n';
    while (u) cout << u << ' ', u = nxt[u];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}