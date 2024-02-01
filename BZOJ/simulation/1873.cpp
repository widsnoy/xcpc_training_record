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

int convert(string s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2)) + 1;
}
struct People {
    string name;
    int co, cnt, dcnt, lst;
} pe[N];
map<string, int> mp;

string fame[11], sk[11], mk[4], com[2];

void pre_init() {
    fame[3] = "killing spree";
    fame[4] = "dominating";
    fame[5] = "mega kill";
    fame[6] = "unstoppable";
    fame[7] = "wicked sick";
    fame[8] = "monster kill";
    fame[9] = "godlike";
    fame[10] = "beyond godlike";
    sk[3] = " is on a killing spree!";
    sk[4] = " is dominating!";
    sk[5] = " has a mega kill!";
    sk[6] = " is unstoppable!";
    sk[7] = " is wicked sick!";
    sk[8] = " has a monster kill!";
    sk[9] = " is godlike!";
    sk[10] = " is beyond godlike. someone kill him!";
    mk[2] = " just got a Double Kill!";
    mk[3] = " just got a Triple Kill!";
    com[0] = "Sentinel";
    com[1] = "Scourge";
}

set<int> mxt[2];
int tr[2][N];
void add(int co, int x, int v) {
    for (; x < N; x += x & -x) tr[co][x] += v;
}
int query(int co, int x) {
    int res = 0;
    for (; x; x -= x & -x) res += tr[co][x];
    return res;
}
int qry(int co, int l, int r) {
    return query(co, r) - query(co, l - 1);
}

void MAIN() {
    int n, m, all_vaild = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pe[i].name >> pe[i].co;
        mp[pe[i].name] = i;
    }
    cin >> m;
    for (int ti = 1; ti <= m; ti++) {
        static string tim, A, B;
        cin >> tim >> A;
        int c_time = convert(tim);
        for (int i = 1; i <= 4; i++) cin >> B;
        //cerr << A << ' ' << B << '\n';
        // 基本
        int idx = mp[A];
        //cout << "## " << ti << ' ' << pe[idx].co << '\n';
        if (A == B) cout << A << " has killed himself.\n";
        else {
            if (!mp.count(B)) cout << A << " has been killed by " << B << ".\n";
            else {
                all_vaild++;
                add(pe[idx].co, ti, 1);
                if (all_vaild == 1) {
                    cout << B << " pawned " << A << "'s head.\n";
                    cout << B << " just drew first blood.\n";
                } else {
                    if (pe[idx].cnt > 2) cout << B << " has just ended " << A << "'s " << fame[min(pe[idx].cnt, 10)] << ".\n";
                    else cout << B << " pawned " << A << "'s head.\n";
                }
                pe[idx].cnt = 0;
            }
        }
        if (!mp.count(B) || A == B) continue;
        // 连杀
        idx = mp[B];
        pe[idx].cnt++;
        if (pe[idx].cnt > 2) cout << B << sk[min(pe[idx].cnt, 10)] << '\n';
        // 多杀
        if (pe[idx].lst == 0 || c_time - pe[idx].lst > 10) pe[idx].lst = c_time, pe[idx].dcnt = 1;
        else {
            pe[idx].lst = c_time;
            pe[idx].dcnt++;
            cout << B << mk[min(3, pe[idx].dcnt)] << '\n';
        }
        // 局势
        if (mxt[pe[idx].co].size() == 5) mxt[pe[idx].co].erase(*mxt[pe[idx].co].begin());
        mxt[pe[idx].co].insert(ti);
        if (mxt[pe[idx].co].size() < 5) continue;
        auto lt = mxt[pe[idx].co].begin();
        if (qry(pe[idx].co, *lt, ti) == 0) cout << "The " << com[pe[idx].co] << " is OWNING!\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    pre_init();
    while (T--) MAIN();
    return 0;
}