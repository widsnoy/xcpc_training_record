//复建...o.o
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
int n, a[N];
void MAIN() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << *max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}