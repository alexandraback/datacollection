#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <cstdlib>
#include <cctype>
#include <bitset>
#include <string>
#include <map>
#include <cassert>
#include <set>

#ifdef PEYEK 
	#define debugln {printf("----OK----\n");}
	#define debug(...) {printf(__VA_ARGS__);}
	#define debugs(...) {printf(":::::--->> ");printf(__VA_ARGS__);}
	#define TIME() printf("%.3lf\n",clock()/(double)CLOCKS_PER_SEC)
#else
	#define debugln {}
	#define debug(...) {}
	#define debugs(...) {}
	#define TIME() {}
#endif

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define FORLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORNLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)<=(_t);++(_i))
#define FORDLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)>=(_t);--(_i))
#define FOREACH(_i,_a) for (__typeof(_a.begin()) _i=_a.begin();_i!=_a.end();++_i)
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
 
using namespace std;
 
const int dr[]={ 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[]={ 0, 1, 0,-1, 1,-1,-1, 1};
const double eps=1e-9;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef pair<double,double> pdd;
typedef vector<pdd> vpdd;
const int INF=0x7FFFFFFF;
const ll INFLL=0x7FFFFFFFFFFFFFFFLL;
const double pi=acos(-1);

template <class T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <class T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> inline void getint(T &num)
{
	bool neg=0;
	num=0;
	char c;
	while ((c=getchar_unlocked()) && (!isdigit(c) && c!='-'));
	if (c=='-')
	{
		neg=1;
		c=getchar_unlocked();
	}
	do num=num*10+c-'0';
	while ((c=getchar_unlocked()) && isdigit(c));
	num*=(neg)?-1:1;
}

void OPEN(string in="input.txt",string out="output.txt")
{
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	return ;
}

//using sokokaleb's template v2.8

vii vc[105];
char x[105];
int n,nodeCnt,cN,len;
int cnt[105],cost[105],cost2[105];

int solve()
{
	debugln;
	int sz = SIZE(vc[0]);
	FOR (i,1,n)
		if (SIZE(vc[i]) != sz) return -1;
	int ans = 0;
	FOR (j,0,sz)
	{
		FOR (i,1,n)
			if (vc[i][j].ss != vc[i-1][j].ss) return -1;
		RESET(cnt,0);
		RESET(cost,0);
		RESET(cost2,0);
		FOR (i,0,n)
			++cnt[vc[i][j].ff];
		int cntt = cnt[0];
		FORN (i,1,100)
		{
			cost[i] += cost[i-1] + cntt;
			cntt += cnt[i];
		}
		cntt = cnt[100];
		FORD (i,99,0)
		{
			cost2[i] += cost2[i+1] + cntt;
			cntt += cnt[i];
		}
		int mn = INF;
		FORN (i,0,100)
			mn = min(mn,cost[i] + cost2[i]);
		ans += mn;
	}
	return ans;
}

int main()
{
	getint(n);
	FORN (tc,1,n)
	{
		getint(n);
		FOR (i,0,n)
		{
			scanf("%s",x);
			len = strlen(x);
			vc[i].clear();
			vc[i].pb(mp(1,x[0]));
			FOR (j,1,len)
				if (x[j] == vc[i].back().ss)
					++vc[i].back().ff;
				else vc[i].pb(mp(1,x[j]));
		}

		// cek
		int stat = solve();
		debugln;
		printf("Case #%d: ",tc);
		if (stat == -1) puts("Fegla Won");
		else printf("%d\n",stat);
	}
	return 0;
}