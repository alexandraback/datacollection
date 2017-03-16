//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

using namespace std;

pair<double,double> p[3005];
double d[3005],d1[3005];
int ans[3005];

int calBetween(double l,double r,int cnt){
	int pos1 = upper_bound(d,d+cnt,l)-d;
	int pos2 = lower_bound(d,d+cnt,r)-d-1;
	if(pos1<=pos2) return pos2-pos1+1;
	return 0;
}

int calEq(double x,int cnt){
	int pos1 = lower_bound(d,d+cnt,x)-d;
	int pos2 = upper_bound(d,d+cnt,x)-d;
	if(pos1<=pos2) return pos2-pos1;
	return 0;
}

int main(void){
#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Desktop/data.in","r",stdin);
	freopen("/Users/mac/Desktop/data.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--){
		static int ca = 1;
		int n;
		scanf("%d",&n);
		printf("Case #%d:\n",ca++);
		FOR(i,n) scanf("%lf %lf",&p[i].first,&p[i].second);
		FOR(i,n){
			int cnt = 0;
			ans[i] = INF;
			FOR(j,n){
				if(j==i) continue;
				double x = p[j].first-p[i].first;
				double y = p[j].second-p[i].second;
				d[cnt++] = atan2(y,x);
			}
			sort(d,d+cnt);
			memcpy(d1,d,sizeof(d));
			if(cnt==0) ans[i] = 0;
			int cnt1 = cnt;
			cnt1 = unique(d1,d1+cnt1)-d1;
			FOR(j,cnt1){
				double ang = d1[j];
				double ang1 = d1[j];
				if(ang<=0) ang1+=PI;
				else ang1-=PI;
				if(ang>ang1) swap(ang,ang1);
				int bet = calBetween(ang,ang1,cnt);
				int eq = calEq(ang,cnt)+calEq(ang1,cnt);
				int left = cnt-bet-eq;
				ans[i] = min(ans[i],min(bet,left));
				if(ans[i]==0) break;
			}
		}
		FOR(i,n) printf("%d\n",ans[i]);
	}
	return 0;
}

