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
int sum[3], mp['Z'];

int get(int st) {
    memset(sum, 0, sizeof sum);
    int res = 0;
    for (int i = st; i <= n; i++) {
        sum[mp[s[i]]]++;
        bool ok = 1;
        for (int j = 0; j < 3; j++) 
            for (int k = j + 1; k < 3; k++) ok &= sum[j] != sum[k];
        res = ok ? max(res, i - st + 1) : res;
    }
    return res;
}

void MAIN() {
    io >> n;
    for (int i = 1; i <= n; i++) io >> s[i];
    int ans = 0;
    for (int i = 1, j = 0; i <= n + 1; i++) {
        if (i == n + 1 || s[i] != s[i - 1]) ans = max(i - 1 - j, ans), j = i - 1;
    }
    mp['B'] = 0, mp['C'] = 1, mp['S'] = 2;
    ans = max({ans, get(1), get(2), get(3)});
    reverse(s + 1, s + n + 1);
    ans = max({ans, get(1), get(2), get(3)});
    io << ans << '\n';
}

int main() {
    //cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    while (T--) MAIN();
    return 0;
}