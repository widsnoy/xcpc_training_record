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

int n;
ll a[N], s[N];
ll stk[N], top;
double ans[N];
void MAIN() {
    scanf("%d", &n); 
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), s[i] = s[i - 1] + a[i];
    for (int i = n; i >= 0; i--) {
        while (top > 1 && (s[stk[top]] - s[i]) * (stk[top - 1] - i) < (s[stk[top - 1]] - s[i]) * (stk[top]- i)) --top;
        ans[i + 1] = (s[stk[top]] - s[i]) * 1.0 / (stk[top] - i);
        stk[++top] = i;
    }
    for (int i = 1; i <= n; i++) printf("%.9f\n", ans[i]);
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

