#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>
 
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<long long> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator

#define S 100
#define N 100

struct P{
	int e, num;
	P(){}
	P(int e, int num):e(e),num(num){}
};

int i,j,k,m,n,l;
char s[S+10];
vp a[N+10];

bool check(){
	repf(i, 1, n-1){
		if (sz(a[i])!=sz(a[0])) return false;
		rep(j, sz(a[0]))
			if (a[0][j].e!=a[i][j].e) return false;
	}
	return true;
}

int gao(){
	vi v;
	int ret=0;
	rep(i, sz(a[0])){
		v.clear();
		rep(j, n) v.pb(a[j][i].num);
		sort(all(v));
		rep(j, n) ret+=abs(v[j]-v[n/2]);
	}
	return ret;
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
    int ts;
    scanf("%d", &ts);
    repf(te, 1, ts){
		scanf("%d", &n);
		rep(i, n){
			a[i].clear();
			scanf("%s", s);
			m = strlen(s);
			k=-1;
			rep(j, m){
				if (k==-1 || a[i][k].e!=s[j])
					a[i].pb(P(s[j], 1)), ++k;
				else
					a[i][k].num++;
			}
		}

		printf("Case #%d: ", te);
		if (check())
			printf("%d\n", gao());
		else puts("Fegla Won");

    }
    return 0;
}
