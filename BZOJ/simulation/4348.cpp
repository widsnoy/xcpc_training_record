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
const int N = 1000 + 5;

int n, siz[N * N];
char s[N][N];
int id[N][N], dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
pii st[N * N], ed[N * N];
void dfs(int x, int y, int idx) {
    id[x][y] = idx;
    siz[idx]++;
    ed[idx] = max(ed[idx], {x, y});
    for (int k = 0; k < 4; k++) {
        int nx = dx[k] + x, ny = dy[k] + y;
        if (nx > n || ny > n || nx < 1 || ny < 1 || s[nx][ny] == 'A' || id[nx][ny] != 0) continue;
        dfs(nx, ny, idx);
    }
}

int check(int x1, int y1, int x2, int y2, int ban) {
    vector<int> vec;
    for (int k = 0; k <= 3; k++) {
        int nx = x1 + dx[k], ny = y1 + dy[k];
        if (nx > n || ny > n || nx < 1 || ny < 1 || s[nx][ny] == 'A' || id[nx][ny] == ban) continue;
        vec.push_back(id[nx][ny]);
    } 
    for (int k = 0; k <= 3; k++) {
        int nx = x2 + dx[k], ny = y2 + dy[k];
        if (nx > n || ny > n || nx < 1 || ny < 1 || s[nx][ny] == 'A' || id[nx][ny] == ban) continue;
        vec.push_back(id[nx][ny]);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int res = 0;
    for (int x : vec) res += siz[x];
    //cerr << ban << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << res << '\n';
    return res; 
}
int check_s(int x1, int y1, int ban) {
    for (int k = 0; k <= 3; k++) {
        int nx = x1 + dx[k], ny = y1 + dy[k];
        if (nx > n || ny > n || nx < 1 || ny < 1 || s[nx][ny] == 'A' || id[nx][ny] == ban) continue;
        return id[nx][ny];
    }
    return -1;
}
int get(int x1, int y1, int x2, int y2, int ban) {
    int ans = 0;
    vector<pii> v, vv;
    int cnt = 0;
    auto test = [&](int x, int y) {
        return (x >= 1 && x <= n && y >= 1 && y <= n && s[x][y] == 'A');
    };
    for (int i = y1 + 1; i < y2; i++) {
        ans = max(ans, check(x1, i, x1 - 1, i, ban));
        ans = max(ans, check(x2, i, x2 + 1, i, ban));
        if (i == y1 + 1 || i == y2 - 1) {
            if (test(x2, i)) cnt++, vv.push_back({x2, i});
            if (test(x1, i)) cnt++, vv.push_back({x1, i});
        }
        else {
            if (test(x1, i)) cnt++, v.push_back({x1, i});
            if (test(x2, i)) cnt++, v.push_back({x2, i});
        }
    }
    for (int i = x1 + 1; i < x2; i++) {
        ans = max(ans, check(i, y1, i, y1 - 1, ban));
        ans = max(ans, check(i, y2, i, y2 + 1, ban));
        if (i == x1 + 1 || i == x2 - 1) {
            if (test(i, y1)) cnt++, vv.push_back({i, y1});
            if (test(i, y2)) cnt++, vv.push_back({i, y2});
        }
        else {
            if (test(i, y1)) cnt++, v.push_back({i, y1});
            if (test(i, y2)) cnt++, v.push_back({i, y2});
        }
    }
    vector<int> f;
    for (auto [x, y] : v) {
        int temp = check_s(x, y, ban);
        if (temp != -1) f.push_back(temp);
    }
    //sort(f.begin(), f.end(), [&](int x, int y) {return siz[x] > siz[y];});
    //f.erase(unique(f.begin(), f.end()), f.end());
    if (f.size() == 1) ans = max(ans, siz[f[0]]);
    else if (f.size() > 1) ans = max(ans, siz[f[0]] + siz[f[1]]);
    for (auto [x1, y1] : vv) {
        for (auto [x2, y2] : v) ans = max(ans, check(x1, y1, x2, y2, ban));
    }
    for (auto [x1, y1] : vv) {
        for (auto [x2, y2] : vv) ans = max(ans, check(x1, y1, x2, y2, ban));
    } 
    return ans + min(cnt, 2);
}

void MAIN() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (s[i][j] == 'B' && !id[i][j]) {
            ++tot;
            st[tot] = {i, j};
            dfs(i, j, tot);
        }
    }
    int ans = 0;
    for (int kt = 1; kt <= tot; kt++) {
        ans = max(ans, siz[kt] + get(st[kt].fi - 1, st[kt].se - 1, ed[kt].fi + 1, ed[kt].se + 1, kt));
        //cerr << kt << ' ' << siz[kt] + get(st[kt].fi - 1, st[kt].se - 1, ed[kt].fi + 1, ed[kt].se + 1, kt) << '\n';
    }
    printf("%d\n", ans);
}

int main() {
    //ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}