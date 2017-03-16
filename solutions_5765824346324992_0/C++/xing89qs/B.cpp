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

int m[1005];
int cnt[1005],cnt1[1005];

int main(void){
#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Desktop/data.in","r",stdin);
	freopen("/Users/mac/Desktop/data.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--){
		static int ca = 1;
		int b,n;
		scanf("%d %d",&b,&n);
		FOR(i,b) scanf("%d",&m[i]);
		if(n<=b){
			printf("Case #%d: %d\n",ca++,n);
			continue;
		}
		LL low = 0,high = 1e18;
		LL ans = 0;
		while(low<=high){
			LL mid = (low+high)>>1;
			LL tot = 0;
			FOR(i,b) tot+=mid/m[i]+1;
			if(tot<n){
				low = mid+1;
				ans = mid;
			}else{
				high = mid-1;
			}
		}
		LL tot = 0;
		FOR(i,b){
			cnt[i] = ans/m[i]+1;
			tot+=ans/m[i]+1;
		}
		LL now = ans+1;
		int res = -1;
		while(tot<n){
			FOR(i,b) if(now%m[i]==0){
				tot++;
				if(tot==n) res = i+1;
			}
			now++;
		}
		printf("Case #%d: %d\n",ca++,res);
	}
	return 0;
}

