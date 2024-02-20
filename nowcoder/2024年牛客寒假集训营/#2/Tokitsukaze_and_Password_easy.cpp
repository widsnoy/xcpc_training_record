//能确定的事情只有啊，今天感觉有点寂寞啊
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

namespace IO {
#define isdigit(x) (x >= '0' && x <= '9')
template<typename T>
inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    if(f) x = -x;
}
template<typename T, typename... Rest>
inline void read(T &x, Rest&... rest) {
    read(x), read(rest...);
}
template<typename T>
inline void write(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
#undef isdigit
}
using namespace IO;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 15;
int n, y, s1, s2, i2;
char s[N];
map<char, int> mp;
int num[5], vis[10], ans;
void calc() {
    int cnt = 0;
    for (auto &[x, y] : mp) {
        y = num[++cnt];
    }
    int x = 0;
    for (int i = 1; i <= n; i++) {
        int v;
        if (s[i] >= 'a' && s[i] <= 'z') v = mp[s[i]];
        else if (s[i] == '_') v = i2;
        else v = s[i] - '0';
        if (i == 1 && v == 0 && n != 1) return;
        x = x * 10 + v;
    }
    //cerr << x << '\n';
    if (x % 8 == 0 && x <= y) ans++; 
}
void dfs(int p) {
    if (p == s1 + 1) {
        if (s2) for (int i = 0; i < 10; i++) i2 = i, calc();
        else calc();
        return;
    }
    for (int i = 0; i < 10; i++) if (!vis[i])  {
        vis[i] = 1;
        num[p] = i;
        dfs(p + 1);
        vis[i] = 0;
    }
}
void MAIN() {
    mp.clear();
    scanf("%d %s %d", &n, s + 1, &y);
    s1 = s2 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') mp[s[i]] = 0;
        if (s[i] == '_') s2 = 1;
    }
    s1 = mp.size();
    memset(vis, 0, sizeof vis);
    ans = 0;
    dfs(1);
    printf("%d\n", ans);
}

int main() {
    //ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    read(T);
    while (T--) MAIN();
    return 0;
}