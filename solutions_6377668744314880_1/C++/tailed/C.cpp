#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair
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
	rep(k, n) {
		P c = ps[k];
		priority_queue<pair<double, int> > Q;
		set<int> s;
		rep(i, n) if (i != k) {
			double a = arg(ps[i] - c);
			if (a > 0) {
				s.insert(i);
				Q.push(mp(a, (i+1)));
				Q.push(mp(a + M_PI, -(i+1)));
			} else {
				Q.push(mp(2 * M_PI + a - M_PI, -(i+1)));
				Q.push(mp(2 * M_PI + a, (i+1)));
			}
		}

		ans[k] = min(ans[k], sz(s));
		ans[k] = min(ans[k], n-1-sz(s));
		while(!Q.empty()) {

			double a = Q.top().first;
			vector<pair<bool, int> > v;
			while(!Q.empty() && abs(a - Q.top().first) < EPS) {
				int i = abs(Q.top().second) - 1;
				bool add = Q.top().second >= 0;
				Q.pop();
				v.push_back(mp(add, i));
			}

			sort(all(v));

			for(auto x : v) {
				int i = x.second;
				if (x.first) s.insert(i);
				else s.erase(i);

				/*
				if (s.count(i)) s.erase(i);
				else s.insert(i);
				*/

				ans[k] = min(ans[k], sz(s));
				ans[k] = min(ans[k], n-1-sz(s));
			}

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

