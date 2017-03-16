#include <bits/stdc++.h>

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
LL INFLL   = 1000000000000000000LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back

#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)

#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))

#define RESET(a, b)   memset(a,b,sizeof(a))
#define ALL(a)        (a).begin(), (a).end()
#define SIZE(a)       (int)a.size()
#define SORT(a)       sort(ALL(a))
#define UNIQUE(a)     (a).erase( unique( ALL(a) ), (a).end() )
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ----- //
int x[10005];

int main() {
	int tc;
	scanf("%d",&tc);
	FOR(T,1,tc) {
		printf("Case #%d: ",T);
		int n,ans1=0,ans2=0;
		scanf("%d",&n);
		FOR(a,0,n-1) {
			scanf("%d",&x[a]);
			if (a) ans1 += max(0,-x[a]+x[a-1]);
		}
		ans2 = INF;
		FOR(a,0,10000) { 
			int cur = 0;
			FOR(b,1,n-1) {
				int eaten = min(x[b-1], a);
				cur += eaten;
				if (x[b-1]-eaten > x[b]) {
					cur = INF+1;
				}
				if (cur > ans2) break;
			}
			MIN(ans2, cur);
		}
		printf("%d %d\n",ans1,ans2);
	}
}
