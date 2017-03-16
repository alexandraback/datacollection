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
		int b,n;
		scanf("%d%d",&b,&n);
		FOR(a,0,b-1) {
			scanf("%d",&x[a]);
		}
		if (n <= b) {
			printf("%d\n",n);
			continue;
		}
		LL l = 1;
		LL r = INFLL;
		int ans = -1;
		while(l <= r) {
			LL m = (l+r)/2;
			LL total = 0;
			vector<LL> ch;
			FOR(a,0,b-1) {
				LL bg = (m+x[a]-1)/x[a];
				total += bg;
				ch.pb(bg*x[a]+x[a]+1);
				ch.pb(bg*x[a]);
				MIN(total, INFLL);
			}
			FOR(a,0,b-1) {
				if (m%x[a] == 0) {
					total++;
					ch.pb(m+1);
					ch.pb(m-1);
					//cout << n << " " << total << endl;
					if (n == total) {
					//	cout << "MASUK " << a << endl;
						ans = a;
					}
				}
				else {
					LL kali = m/x[a];
					ch.pb(kali*x[a]);
					ch.pb(kali*x[a]+x[a]);
					
				}
			}
			LL nx = -INFLL;
			LL pr = INFLL;
			FOR(a,0,SIZE(ch)-1) {
				if (ch[a] < m) {
					MAX(nx, ch[a]);
				}
				if (ch[a] > m) {
					MIN(pr, ch[a]);
				}
			}
			//cout << l << " " << r << " " << m << " " << total << " " << pr << " " << nx << endl;
			if (ans != -1) break;
			if (nx == -INFLL && pr == INFLL) {
				break;
			}
			if (nx == -INFLL) {
				l = pr;
			}
			else if (pr == INFLL) {
				r = nx;
			}
			else if (total >= n) {
				r = nx;
			}
			else {
				l = pr;
			}
		}
		printf("%d\n",ans+1);
	}
}
