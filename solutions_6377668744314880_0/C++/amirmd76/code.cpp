#include <bits/stdc++.h>
//#include "testlib.h"
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define umap unordered_map
#define smax(x, y) x = max((x), (y))
#define smin(x, y) x = min((x), (y))
#define double long double
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
typedef vector<int> vi;
const int maxn = 6 + 10;
int n;
//#define REMOVE_REDUNDANT


typedef double T;
const T EPS = 1e-7;
struct PT { 
  T x, y; 
  PT() {} 
  PT(T x, T y) : x(x), y(y) {}
  pii PII(){return pii(x, y);}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
  PT operator - (PT a){return PT(x - a.x, y - a.y);}
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

#ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  
#ifdef REMOVE_REDUNDANT
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
#endif
}
pii p[maxn];
main(){
	iOS;
	int T;
	cin >> T;
	For(test, 1, T + 1){
		cout << "Case #" << test << ":\n";
		cin >> n;
		For(i,0,n)
			cin >> p[i].x >> p[i].y;
		For(i,0,n){
			int ans = n-1;
			For(mask,0,1 << n)	if((mask >> i) & 1){
				vector<PT> v;
				For(j,0,n)
					if((mask >> j) & 1)
						v.pb(PT(p[j].x, p[j].y));
				ConvexHull(v);
								bool ok = 0;
				rep(a, v)
					if(a.PII() == p[i])
						ok = true;
				PT q(p[i].x, p[i].y);
				For(i,0,v.size()){
					int j = (i+1)%(int)v.size();
					double c = cross(q - v[i], v[j] - v[i]);
					if(fabs(c) < 1e-4)
						ok = 1;

				}
				if(ok)
					smin(ans, n - __builtin_popcount(mask));
			}
			cout << ans << endl;

		}
	}
}

