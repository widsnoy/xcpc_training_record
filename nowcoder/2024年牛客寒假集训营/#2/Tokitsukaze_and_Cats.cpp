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

int n, m, k;
int get(int x, int y) {
    return x * (m + 1) + (y + 1);
}
map<pair<int, int>, int> mp;
void Set(int x, int y, int x1, int y1) {
    mp[{get(x, y), get(x1, y1)}] = 1;
    mp[{get(x1, y1), get(x, y)}] = 1;
}
void MAIN() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        Set(x, y, x - 1, y);
        Set(x, y, x + 1, y);
        Set(x, y, x, y - 1);
        Set(x, y, x, y + 1);
    }
    cout << mp.size() / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}