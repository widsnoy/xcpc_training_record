#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 3e5 + 5;
int n, a[N];
void MAIN() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += i;
    set<int> used, not_used;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!used.count(a[i])) not_used.insert(a[i]);
        auto it = not_used.upper_bound(a[i]);
        it = prev(it);
        ans.push_back(*it);
        used.insert(*it);
        not_used.erase(*it);
        if (!used.count(*it - 1)) not_used.insert(*it - 1);
    }
    sort(ans.begin(), ans.end(), greater());
    for (int x : ans) cout << x << ' ';
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

