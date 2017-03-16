#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef long long ll;

int TC;

typedef complex<double> P;
typedef pair<P, P> L;
typedef pair<P, double> C;
typedef vector<P> poly;
namespace std { bool operator < (const P &a, const P &b) { return make_pair(real(a), imag(a)) < make_pair(real(b), imag(b)); } }

const double EPS = 1e-9;
#define DI(l) ((l).second-(l).first)
#define EQ(a, b) (abs((a)-(b)) < EPS)
#define CCW(l, a) ccw((l).first, (l).second, (a))

double cross(const P &a, const P &b) { return imag(conj(a)*b); }
double dot(const P &a, const P &b) { return real(conj(a)*b); }
/* ccw(a, b, c)
 * +1: counter clockwise
 * -1: clockwise
 * +2: c--a--b    on L
 * -2:    a--b--c on L
 *  0: c is on a--b (include a and b)
 */
int ccw(P a, P b, P c) {
	double d = cross(b -= a, c -= a);
	return d>EPS ? 1 : d<-EPS ? -1 : dot(b,c)<-EPS ? 2 : norm(b)+EPS<norm(c) ? -2 : 0;
}
bool parallel(const L &l, const L &m) { return EQ(cross(DI(l), DI(m)), 0); }
bool sameline(const L &l, const L &m) { return parallel(l, m) && EQ(cross(DI(l), m.second-l.first), 0); }
bool intersectLL(const L &l, const L &m) { return !parallel(l, m) || sameline(l, m); }
bool intersectLP(const L &l, const P &p) { return EQ(cross(l.second-p, l.first-p), 0); }
bool intersectSS(const L &s, const L &t) { return CCW(s,t.first)*CCW(s,t.second)<=0 && CCW(t,s.first)*CCW(t,s.second)<=0; }
bool intersectSP(const L &s, const P &p) { return EQ(abs(s.first-p)+abs(s.second-p)-abs(DI(s)), 0); }


poly convex_hull(vector<P> ps) {
	int n = sz(ps), k = 0;
	sort(all(ps));
	poly v(2*n);
	for(int i=0; i<n; v[k++]=ps[i++])
		while(k >= 2 && ccw(v[k-2], v[k-1], ps[i]) <= 0) --k;
	for(int i=n-2, t=k+1; i>=0; v[k++]=ps[i--])
		while(k >= t && ccw(v[k-2], v[k-1], ps[i]) <= 0) --k;
	v.resize(k-1);
	return v;
}


void solve() {
	int n;
	cin >> n;
	vector<P> ps;
	rep(i, n) {
		double x, y;
		cin >> x >> y;
		ps.push_back(P(x, y));
	}

	vector<int> ans(n, n-1);
	rep(s, 1<<n) {
		if (s == 0) continue;
		vector<P> qs;
		rep(i, n) if (s>>i&1) qs.push_back(ps[i]);
		poly v = convex_hull(qs);
		rep(i, sz(v)) {
			L l(v[i], v[(i+1)%sz(v)]);
			rep(j, n) if (intersectSP(l, ps[j])) ans[j] = min(ans[j], n - sz(qs));
		}
	}
	
	cout << endl;
	rep(i, n) cout << ans[i] << endl;
}
int main() {
	int T; cin >> T;
	for(TC=1; TC<=T; TC++) {
		cout << "Case #" << TC << ": ";
		solve();
	}
}

