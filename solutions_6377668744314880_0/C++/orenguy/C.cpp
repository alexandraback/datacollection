#include <bits/stdc++.h>

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
LL INFLL   = 1000000000000000000LL;

#define fi            first
#define se            second
#define x            first
#define y            second
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

pll p[300001];
int id[300001];
pair<pll,int> q[300001];
pll lo[300001];
int loid[300001];
pll hi[300001];
int hiid[300001];
int ans[300001];

LL cross(pll O, pll A,pll B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int main() {
	int tc;
	scanf("%d",&tc);
	FOR(T,1,tc) {
		printf("Case #%d:\n",T);
		int n;
		scanf("%d",&n);
		FOR(a,0,n-1) {
			scanf("%lld %lld",&q[a].fi.fi,&q[a].fi.se);
			ans[a] = INF;
			q[a].se = a;
		}
		sort(q,q+n);
		FOR(mask,0,(1 << n)-1) {
			int m = 0;
			FOR(b,0,n-1) {
				if (mask & (1 << b)) {
					id[m] = q[b].se;
					p[m++] = q[b].fi;
				}
			}
			LL clo = 0;
			FOR(a,0,m-1)
			{
				while (clo >=2 && cross(lo[clo-1], lo[clo], p[a]) < 0) clo--;
				lo[++clo] = p[a];
				loid[clo] = id[a];
			}
			LL chi = 0;
			FORD(a,m-1,0)
			{
				while (chi >=2 && cross(hi[chi-1], hi[chi], p[a]) < 0) chi--;
				hi[++chi] = p[a];
				hiid[chi] = id[a];
			}
			FOR(a,1,chi) {
				MIN(ans[hiid[a]], n-__builtin_popcount(mask));
			}
			FOR(a,1,clo) {
				MIN(ans[loid[a]], n-__builtin_popcount(mask));
			}
		}
		FOR(a,0,n-1) {
			printf("%d\n",ans[a]);
		}
	}
}
