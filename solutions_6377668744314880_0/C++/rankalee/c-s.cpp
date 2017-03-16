#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double EPS = 1e-8, INF = 1e12, PI = acos(-1.0);
typedef complex<double> P;
namespace std{
	bool operator<(const P& a, const P& b){
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
inline double cross(const P& a, const P& b){ return imag(conj(a)*b); }
inline double dot(const P& a, const P& b){ return real(conj(a)*b); }
struct L : public vector<P>{
	L(const P &a, const P &b) {
		push_back(a); push_back(b);
	}
};
typedef vector<P> G;

inline int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if(cross(b, c) > 0)   return +1;		// counter clockwise
	if(cross(b, c) < 0)   return -1;		// clockwise
	if(dot(b, c) < 0)     return +2;		// c--a--b on line
	if(norm(b) < norm(c)) return -2;		// a--b--c on line
	return 0;
}
vector<P> convex_hull(vector<P> ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<P> ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}

int main(){
	int cs; cin >> cs;
	rep(CS, cs){
		
		int n; cin >> n;
		G g;
		rep(i, n){
			int x, y; cin >> x >> y;
			g.pb(P(x, y));
		}
		printf("Case #%d:\n", CS + 1);
		rep(i, n){
			
			int ans = n;
			rep(j, 1 << n) if(j & 1 << i){
				G h;
				bool ok = 0;
				if(__builtin_popcount(j) <= 2){
					ans = min(ans, n - __builtin_popcount(j));
					continue;
				}
				
				rep(k, n) if(j & 1 << k) h.pb(g[k]);
				
				h = convex_hull(h);
				rep(k, h.size()) if(abs(h[k] - g[i]) < EPS){
					ok = 1;
					break;
				}
				rep(k, h.size()) if(ccw(g[i], h[k], h[(k + 1) % h.size()]) == 2){
					ok = 1;
					break;
				}
				
				if(ok) ans = min(ans, n - __builtin_popcount(j));
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}