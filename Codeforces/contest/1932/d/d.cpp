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
int n, b, mp['Z'], a[5];
void MAIN() {
    mp['C'] = 1, mp['D'] = 2, mp['H'] = 3, mp['S'] = 4;
    cin >> n;
    string s;
    cin >> s;
    b = mp[s[0]];
    memset(a, 0, sizeof a);
    vector<string> v[5];
    for (int i = 1; i <= n + n; i++) {
        cin >> s;
        a[mp[s[1]]]++;
        v[mp[s[1]]].push_back(s);
    }
    for (int k = 1; k <= 4; k++) sort(v[k].begin(), v[k].end(), greater());
    int re = 0;
    vector<string> ans;
    for (int i = 1; i <= 4; i++) if (b != i) {
        re += a[i] % 2;
        string res;
        while (v[i].size() >= 2) {
            res = v[i].back();
            v[i].pop_back();
            res += " ";
            res += v[i].back();
            v[i].pop_back();
            ans.push_back(res);
        }
    }
    if (a[b] < re) return cout << "IMPOSSIBLE\n", void();
    for (auto x : ans) cout << x << '\n';
    for (int i = 1; i <= 4; i++) if (b != i && a[i] % 2) {
        cout << v[i].back() << ' ' << v[b].back() << '\n';
        v[b].pop_back();
    }
    while (v[b].size()) {
        cout << v[b].back() << ' ';
        v[b].pop_back();
        cout << v[b].back() << '\n';
        v[b].pop_back();
    }
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

