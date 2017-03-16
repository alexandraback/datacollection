#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vb> vvb;
typedef vector<vs> vvs;
typedef vector<vl> vvl;

int inf = 0x3f3f3f3f;
double eps = 10e-10;
ll mod = 1000000007ll;

#define rep(k, a, b) for (int k = (a); k < int(b); k++)
#define sz(a) int(a.size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define x first
#define y second
#define mi(r, c, v) vvi(r, vi(c, v))
#define rrep(k, a, b) for (int k = (a); k >= int(b); k--)
#define irep(k, a) for (auto& k : (a))
#define md(r, c, v) vvd(r, vd(c, v))
#define mb(r, c, v) vvb(r, vb(c, v))
#define ms(r, c, v) vvs(r, vs(c, v))
#define ml(r, c, v) vvl(r, vl(c, v))
#define mc(r, c, v) vs(r, string(c, v))
#define add(i, j) ((i) + (j)) % mod
#define mul(i, j) ((i) * (j)) % mod
#define bits(n) int(__builtin_popcount(n))

template<class T>
struct point {
	T x, y;
	point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {}
	point& operator+=(point p) { x += p.x; y += p.y; return *this; }
	point& operator-=(point p) { x -= p.x; y -= p.y; return *this; }
	point& operator*=(T c) { x *= c; y *= c; return *this; }
	point& operator/=(T c) { x /= c; y /= c; return *this; }
	point operator+(point p) const { return point(x + p.x, y + p.y); }
	point operator-(point p) const { return point(x - p.x, y - p.y); }
	point operator*(point c) const { return point(x * c, y * c); }
	point operator/(point c) const { return point(x / c, y / c); }
	bool operator<(point p) const { return x < p.x || (x == p.x && y < p.y); }
	bool operator==(point p) const { return x == p.x && y == p.y; }

	T dot(point p) const { return x * p.x + y * p.y; }
	T cross(point p) const { return x * p.y - y * p.x; }
	T norm2() const { return x * x + y * y; }
	T dist2(point p) const { return (*this - p).norm2(); }
	T sa2(point p1, point p2) const { return (p1 - *this).cross(p2 - *this); }
	T dist(point p) const { return sqrt(dist2(p)); }
	int above(point p) const { return p.y > y || (p.y == y && p.x > x) ? 1 : (p.y < y || p.x < x ? -1 : 0); }
};
template<class T>
istream& operator>>(istream& in, point<T>& p) { return in >> p.x >> p.y; }
typedef point<int> pti;
typedef point<double> ptd;

template<class T>
vector<point<T>> graham(vector<point<T>>& p, bool allp = false) {
	int rev;
	if (sz(p) < 3)
		return p;
	rep(i, 1, sz(p)) {
		if (p[i] < p[0])
			swap(p[i], p[0]);
	}
	sort(p.begin() + 1, p.end(), [&](point<T> p1, point<T> p2) {
		T d = p[0].sa2(p1, p2);
		return d > T(0) ? true : (d < T(0) ? false : p[0].dist2(p1) > p[0].dist2(p2));
	});
	for (rev = 2; rev < sz(p); rev++) {
		if (p[0].sa2(p[rev - 1], p[rev]) != T(0))
			break;
	}
	reverse(p.begin() + 1, p.begin() + rev);
	vector<point<T>> hull = { p[0], p[1] };
	rep(i, 2, sz(p)) {
		while (sz(hull) > 1) {
			T d = hull[sz(hull) - 2].sa2(hull[sz(hull) - 1], p[i]);
			if (d > T(0) || (d == T(0) && allp))
				break;
			hull.pop_back();
		}
		hull.pb(p[i]);
	}
	if (!allp && sz(hull) > 2 && hull[sz(hull) - 2].sa2(hull[sz(hull) - 1], hull[0]) == T(0))
		hull.pop_back();
	return hull;
}

int main() {
	int T, n;
	cin >> T;
	rep(X, 0, T) {
		cin >> n;
		vector<point<ll>> pts(n);
		vi best(n);
		irep(p, pts)
			cin >> p.x >> p.y;

		printf("Case #%d:\n", X + 1);
		rep(i, 1, 1 << n) {
			vector<point<ll>> curp;
			rep(j, 0, n) {
				if ((i & (1 << j)) != 0)
					curp.pb(pts[j]);
			}
			vector<point<ll>> hull = graham(curp, true);
			rep(j, 0, sz(hull)) {
				rep(k, 0, n) {
					if (hull[j] == pts[k])
						best[k] = max(best[k], sz(curp));
				}
			}
		}

		rep(i, 0, n)
			printf("%d\n", n - best[i]);
	}
}
