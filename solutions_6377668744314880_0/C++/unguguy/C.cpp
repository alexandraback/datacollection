#include <functional>
#include <algorithm>
#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef long long        LL;
typedef pair<LL, LL>   pii;
typedef pair<LL, pii>   piii;
typedef vector<LL>      vi;
typedef vector<pii>      vii;
typedef vector<piii>     viii;

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
inline void inpLL( LL &n ) {
  n=0; register LL ch = getchar_unlocked(); bool sign = 0;
  while(ch < 48 || ch > 57) { if(ch == '-') sign = 1; ch = getchar_unlocked(); }
  while(ch >= 48 && ch <= 57) { n = (n << 3) + (n << 1) + ch - 48, ch = getchar_unlocked(); }
  if(sign) n = -n;
}

inline LL sqr(LL x){return x * x;}
inline LL cube(LL x){return x * x * x;}
inline LL sqrLL(LL x){return x * x;}
inline LL cubeLL(LL x){return x * x * x;}

const LL LLINF      = 9223372036854775807LL;
const LL LLINF17    = 100000000000000000LL;
const LL INF       = 2147483647;
const LL INF9      = 1000000000;
const LL MOD       = 1000000007;
const double eps    = 1e-7;
const double PI     = acos(-1.0);

#define FOR(a,b,c)   for (LL (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (LL (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (LL (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)

#define RESET(a,b)   memset(a,b,sizeof(a)) 
#define SYNC         ios_base::sync_with_stdio(0);
#define SIZE(a)      (LL)(a.size())
#define MIN(a,b)     (a) = min((a),(b))
#define MAX(a,b)     (a) = max((a),(b))
#define ALL(a)       a.begin(),a.end()
#define RALL(a)      a.rbegin(),a.rend()
#define SIZE(a)      (LL)(a.size())
#define LEN(a)       (LL)(a.length())

#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair

LL dr[] = {1,0,-1,0,-1,1,1,-1};
LL dc[] = {0,-1,0,1,1,1,-1,-1};

struct PT {
  LL idx; 
  LL x, y; 
  PT() {} 
  PT(LL idx, LL x, LL y) : idx(idx), x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

LL cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
LL area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (LL i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (LL i = (LL) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}


LL t, n;
pii arr[3005];
vector<PT> v;
bool lol[20];
LL ans[3005];
int main(){
	scanf("%lld",&t);
	REPN(tc,t) {
		scanf("%lld",&n);
		
		REP(i,n) {
			scanf("%lld %lld",&arr[i].fi,&arr[i].se);
			ans[i] = LLINF17;
		}
		
		for (LL i = 1; i < (1 << n); i++) {
			v.clear();
			LL popcount = 0;
			RESET(lol,0);
			for (LL j = 0; j < n; j++) {
				if (i & (1 << j)) {
					v.pb(PT(j, arr[j].fi, arr[j].se));
					popcount++;
				}
			}

			ConvexHull(v);
			v.pb(v[0]);

			LL cut = n - popcount;
			
			REP(j,n) {
				REP(k,SIZE(v)-1) {
					PT cur = v[k];
					PT next = v[k+1];
					if ((arr[j].se - cur.y) * (next.x - arr[j].fi) == (next.y - arr[j].se) * (arr[j].fi - cur.x)) {
						lol[j] = 1;
					}
				}
			}

			REP(k,SIZE(v)) {
				lol[v[k].idx] = 1;
			}

			REP(j,n) {
				if (lol[j]) {
					MIN(ans[j], cut);
				}
			}
		}

		printf("Case #%lld:\n",tc);
		REP(i,n) {
			printf("%lld\n",ans[i]);
		}
	}

	return 0;
}