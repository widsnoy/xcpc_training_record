#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 2e5 + 5;
int n, m, a[N];
string s;
void MAIN() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> s;
    int l = 1, r = n;
    vector<int> vec, ans;
    for (auto ch : s) {
        if (ch == 'L') vec.push_back(a[l++]);
        else vec.push_back(a[r--]);
    }
    reverse(vec.begin(), vec.end());
    int res = 1;
    for (auto x : vec) {
        res = res * x % m;
        ans.push_back(res);
    }
    reverse(ans.begin(), ans.end());
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

