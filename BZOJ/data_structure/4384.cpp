//能确定的事情只有啊，今天感觉有点寂寞啊
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

struct control{
	int ct,val;
	control(int Ct,int Val=-1):ct(Ct),val(Val){}
	inline control operator()(int Val){
		return control(ct,Val);
	}
}_endl(0),_prs(1),_setprecision(2);
struct FastIO{
	#define IOSIZE 1000000
	char in[IOSIZE],*p,*pp,out[IOSIZE],*q,*qq,ch[20],*t,b,K,prs;
	FastIO():p(in),pp(in),q(out),qq(out+IOSIZE),t(ch),b(1),K(6){}
	~FastIO(){fwrite(out,1,q-out,stdout);}
	inline char getch(){
		return p==pp&&(pp=(p=in)+fread(in,1,IOSIZE,stdin),p==pp)?b=0,EOF:*p++;
	}
	inline void putch(char x){
		q==qq&&(fwrite(out,1,q-out,stdout),q=out),*q++=x;
	}
	inline void puts(const char str[]){fwrite(out,1,q-out,stdout),fwrite(str,1,strlen(str),stdout),q=out;}
	inline void getline(string& s){
		s="";
		for( char ch;(ch=getch())!='\n'&&b;)s+=ch;
	}
	#define indef(T) inline FastIO& operator>>(T& x){\
		x=0; char f=0,ch;\
		while(!isdigit(ch=getch())&&b)f|=ch=='-';\
		while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getch();\
		return x=f?-x:x,*this;\
	}
	indef(int)
	indef(long long)
	inline FastIO& operator>>(char& ch){return ch=getch(),*this;}
	inline FastIO& operator>>(string& s){
		s=""; char ch;
		while(isspace(ch=getch())&&b);
		while(!isspace(ch)&&b)s+=ch,ch=getch();
		return *this;
	}
	inline FastIO& operator>>(double& x){
		x=0; char f=0,ch;
        double d=0.1;
        while(!isdigit(ch=getch())&&b)f|=(ch=='-');
        while(isdigit(ch))x=x*10+(ch^48),ch=getch();
        if(ch=='.')while(isdigit(ch=getch()))x+=d*(ch^48),d*=0.1;
        return x=f?-x:x,*this;
	}
	#define outdef(_T) inline FastIO& operator<<(_T x){\
		!x&&(putch('0'),0),x<0&&(putch('-'),x=-x);\
		while(x)*t++=x%10+48,x/=10;\
		while(t!=ch)*q++=*--t;\
		return *this;\
	}
	outdef(int)
	outdef(long long)
	inline FastIO& operator<<(char ch){return putch(ch),*this;}
	inline FastIO& operator<<(const char str[]){return puts(str),*this;}
	inline FastIO& operator<<(const string& s){return puts(s.c_str()),*this;}
	inline FastIO& operator<<(double x){
		 int k=0;
		this->operator<<(int(x));
		putch('.');
		x-=int(x);
		prs&&(x+=5*pow(10,-K-1));
		while(k<K)putch(int(x*=10)^48),x-=int(x),++k;
		return *this;
	}
	inline FastIO& operator<<(const control& cl){
		switch(cl.ct){
			case 0:putch('\n');break;
			case 1:prs=cl.val;break;
			case 2:K=cl.val;break;
		}
	}
	inline operator bool(){return b;}
}io;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 1e6 + 5;
const int inf = 1e9;

int n;
char s[N];

struct node {
    // **c=0 <=> null
    pii mx[2], mn[2];
    node operator + (const node &q) const {
        node z;
        node x = *this, y = q;
        for (int k = 0; k < 2; k++) {
            if (x.mx[k].se == 0) x.mx[k].fi = -inf;
            if (x.mn[k].se == 0) x.mn[k].fi = inf;
            if (y.mx[k].se == 0) y.mx[k].fi = -inf;
            if (y.mn[k].se == 0) y.mn[k].fi = inf;
            z.mx[k].fi = -inf, z.mn[k].fi = inf;
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (x.mx[i].se == y.mx[j].se) {
                    if (x.mx[i].fi > y.mx[j].fi) y.mx[j] = {-inf, 0};
                    else x.mx[i] = {-inf, 0};
                }
                if (x.mn[i].se == y.mn[j].se) {
                    if (x.mn[i].fi < y.mn[j].fi) y.mn[j] = {inf, 0};
                    else x.mn[i] = {inf, 0};
                }
            }
        }
        for (int k = 0; k < 2; k++) {
            z.mx[0] = max({z.mx[0], x.mx[k], y.mx[k]});
            z.mn[0] = min({z.mn[0], x.mn[k], y.mn[k]});
        }
        for (int k = 0; k < 2; k++) {
            if (z.mx[0] == x.mx[k]) x.mx[k] = {-inf, 0};
            if (z.mx[0] == y.mx[k]) y.mx[k] = {-inf, 0};
            if (z.mn[0] == x.mn[k]) x.mn[k] = {inf, 0};
            if (z.mn[0] == y.mn[k]) y.mn[k] = {inf, 0};
        }
        for (int k = 0; k < 2; k++) {
            z.mx[1] = max({z.mx[1], x.mx[k], y.mx[k]});
            z.mn[1] = min({z.mn[1], x.mn[k], y.mn[k]});
        }
        return z;
    }
};
int lim;
node tr[2][N];
void insert(int tp, int x, node v) {
    for (; x <= lim; x += x & -x) {
        tr[tp][x] = tr[tp][x] + v;
    }
}
node qry(int tp, int x) {
    node res;
    for (; x; x -= x & -x) {
        res = res + tr[tp][x];
    }
    return res;
}
int sum[N][3], mp['Z'], a[N][3], p[N];

void MAIN() {
    io >> n;
    for (int i = 1; i <= n; i++) io >> s[i];
    int ans = 0;
    for (int i = 1, j = 0; i <= n + 1; i++) {
        if (i == n + 1 || s[i] != s[i - 1]) ans = max(i - 1 - j, ans), j = i - 1;
    }
    mp['B'] = 0, mp['C'] = 1, mp['S'] = 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) sum[i][j] = sum[i - 1][j];
        sum[i][mp[s[i]]]++;
    }
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        int c = -1;
        for (int j = 0; j < 3; j++) {
            for (int k = j + 1; k < 3; k++) {
                a[i][++c] = sum[i][j] - sum[i][k];
                vec.push_back(a[i][c]);
            }
        }
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 0; i <= n; i++) for (int j = 0; j < 3; j++) 
        a[i][j] = lower_bound(vec.begin(), vec.end(), a[i][j]) - vec.begin() + 1;
    vector<int>().swap(vec); 
    for (int i = 0; i <= n; i++) vec.push_back(a[i][1]);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    lim = vec.size() + 1;
    iota(p, p + n + 1, 0);
    sort(p, p + n + 1, [&](int x, int y) {return a[x][0] < a[y][0];});
    for (int i = 0, j = 0; i <= n; i++) {
        while (j < n && a[p[i]][0] == a[p[j + 1]][0]) ++j;
        for (int k = i; k <= j; k++) {
            int pos = lower_bound(vec.begin(), vec.end(), a[p[k]][1]) - vec.begin() + 1;
            node x = qry(0, pos - 1), y = qry(1, lim - pos - 1);
            for (int r = 0; r < 2; r++) {
                if (x.mx[r].se != 0 && x.mx[r].se != a[p[k]][2]) ans = max(ans, abs(p[k] - x.mx[r].fi));
                if (x.mn[r].se != 0 && x.mn[r].se != a[p[k]][2]) ans = max(ans, abs(p[k] - x.mn[r].fi));
                if (y.mx[r].se != 0 && y.mx[r].se != a[p[k]][2]) ans = max(ans, abs(p[k] - y.mx[r].fi));
                if (y.mn[r].se != 0 && y.mn[r].se != a[p[k]][2]) ans = max(ans, abs(p[k] - y.mn[r].fi));
            }
        }
        for (int k = i; k <= j; k++) {
            int pos = lower_bound(vec.begin(), vec.end(), a[p[k]][1]) - vec.begin() + 1;
            node x;
            x.mx[0] = {p[k], a[p[k]][2]};
            x.mn[0] = x.mx[0];
            insert(0, pos, x);
            insert(1, lim - pos, x);
        }
        i = j;
    }
    io << ans << '\n';
}

int main() {
    //cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    while (T--) MAIN();
    return 0;
}