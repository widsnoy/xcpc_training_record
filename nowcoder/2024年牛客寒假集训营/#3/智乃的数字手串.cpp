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
const int N = 30 + 5;
int n, a[N];
void MAIN() {
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] &= 1, v.push_back(a[i]);
    int cnt = 0;
    while (true) {
        int flag = 0, pos = 0;
        for (int i = 0; i < v.size(); i++) {
            int j = (i + 1) % v.size();
            if (v[i] == v[j]) {
                flag = 1;
                pos = i;
                break;
            }
        }
        if (!flag) break;
        v.erase(v.begin() + pos);
        cnt ^= 1;
    }
    if (v.size() == 1) cout << (cnt ? "zn" : "qcjj") << '\n';
    else cout << (1 - cnt ? "zn" : "qcjj") << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}