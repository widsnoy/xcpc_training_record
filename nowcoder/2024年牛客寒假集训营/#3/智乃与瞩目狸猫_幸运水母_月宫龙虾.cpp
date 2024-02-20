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

void MAIN() {
    string s, t;
    cin >> s >> t;
    if (s[0] >= 'a' && s[0] <= 'z') s[0] = s[0] - 'a' + 'A';    
    if (t[0] >= 'a' && t[0] <= 'z') t[0] = t[0] - 'a' + 'A';
    cout << (s[0] == t[0] ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) MAIN();
    return 0;
}