#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 5e5 + 5;

int n, q, tr[N];
string s;
void ins(int x) {
    for (; x <= n; x += x & -x) tr[x] ^= 1;
}
void ins(int l, int r) {
    ins(l);
    if (r < n) ins(r + 1);
}
int qry(int x) {
    int res = 0;
    for (; x; x -= x & -x) res ^= tr[x];
    return res;
}

void MAIN() {
    cin >> n >> q;
    cin >> s;
    s = " " + s;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        if (i < n && s[i] == s[i + 1]) st.insert(i);
        if (s[i] == '1') ins(i, i);
    }
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            if (l != 1) {
                if (qry(l) == qry(l - 1)) st.erase(l - 1);
                else st.insert(l - 1);
            }
            if (r != n) {
                if (qry(r) == qry(r + 1)) st.erase(r);
                else st.insert(r);
            }
            ins(l, r);
        } else {
            auto it = st.lower_bound(l);
            if (it != st.end() && *it < r) cout << "No\n";
            else cout << "Yes\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
} 

