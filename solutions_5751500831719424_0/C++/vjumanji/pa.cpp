// directives 
	#include <stdio.h>
	#include <vector>
	#include <map>
	#include <set>
	#include <deque>
	#include <queue>
	#include <algorithm>
	#include <iostream>
	#include <cmath>
	#include <cstring>
	#include <typeinfo>
	#include <sstream>
// 
using namespace std;
// macros 
	#define FOR(i,a,b)      for(int i(a);i<b;++i)
	#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
	#define REP(i,n)        FOR(i,0,n)
	#define CL(a,x)         memset(a,x,sizeof(a))
	#define FL(a,x)			fill_n(a,sizeof(a)/sizeof(a[0]),x)
	#define asort(a,n)		sort(a,a+n)
	#define vsort(v,n)		sort(v.begin(), v.begin()+n)
	#define sz(x)			x.size()
	#define all(x)			x.begin(), x.end()
	#define SSTR( x )		dynamic_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << x ) ).str()
// 

typedef long long LL;
typedef vector<int> vi;
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
LL rLL() { LL x; if(scanf("%lld",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }

string a, b;

int solve (int i, int j)
{
	int n = sz(a), m = sz(b);

	if (i == n)
	{
		if (j == m) return 0;
		for (int k = j; k < m; k++) if (b[k]!=b[k-1]) return -1;
		return m - j;
	}
	if (j == m)
	{
		for (int k = i; k < n; k++) if (a[k]!=a[k-1]) return -1;
		return n - i;
	}

	if (a[i] == b[j]) return solve (i+1, j+1);
	int ans = -1;
	if (i > 0 && a[i-1] == b[j]) {
		ans = solve (i, j+1);
	}
	if (j > 0 && b[j-1] == a[i]) {
		int ans2 = solve (i+1, j);
		if (ans == -1) ans = ans2;
		else if (ans2 != -1 && ans2 < ans) ans = ans2;
	}
	if (ans != -1) ans++;
	return ans;
}
int main()
{
	int T = rint();
	REP(t,T)
	{
		int n;
		cin >> n >> a >> b;
		printf ("Case #%d: ", t+1);
		int r = solve (0,0);
		if (r == -1) printf("Fegla Won\n");
		else printf("%d\n", r);
	}
	return 0;
}
