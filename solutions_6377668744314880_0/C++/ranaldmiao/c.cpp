#include <bits/stdc++.h>
#define EPS 1e-9
#define PI 3.141592653589793
using namespace std;
typedef long long ll;

// points are treated as vectors
struct point {
	ll x, y;
	point(const point& other): x(other.x), y(other.y) {}
	point(ll _x = 0, ll _y = 0): x(_x), y(_y) {}
	point operator+(const point& other) const { return point(x + other.x, y + other.y); }
	point operator-(const point& other) const { return point(x - other.x, y - other.y); }
	point operator*(const ll& other) const { return point(x * other, y * other); }
	point operator/(const ll& other) const { return point(x / other, y / other); }
	point operator-() const { return point(-x, -y); }
	bool operator==(const point& other) const { return x == other.x && y == other.y; }
	bool operator!=(const point& other) const { return x != other.x || y != other.y; }
	inline ll dot(const point& other) const { return x * other.x + y * other.y; }
	// z-component of cross product of (x1, y1, 0) and (x2, y2, 0), which gives signed area of paralellogram
	inline ll cross(const point& other) const { return x * other.y - y * other.x; }
	inline ll sqnorm() const { return x * x + y * y; } // squared norm = squared distance
	inline double norm() const { return sqrt(x * x + y * y); } // norm = length
	inline double angle() const { return atan2(y, x); } // angle in radians

	point normalize() const { // use this to normalize the point/vector
		double length = norm();
		return point(x / length, y / length);
	}
	point rotate(double angle) const { // rotate the point/vector
		double cs = cos(angle), sn = sin(angle);
		return point(cs * x - sn * y, sn * x + cs * y);
	}
	inline point perp() const { return point(-y, x); } // rotate by 90 degrees counterclockwise
};

// ccw < 0 - clockwise, ccw == 0 - collinear, ccw > 0 - counterclockwise. abs(ccw) = area of paralellogram.
inline ll ccw(const point& a, const point& b, const point& c) { return (b - a).cross(c - b); }
inline bool collinear(const point& a, const point& b, const point& c) { return abs(ccw(a, b, c)) == 0; }

// polygons are lists of points with no repeated end vertices
struct polygon {
	vector<point> p;
	polygon(vector<point> _p = vector<point>()): p(_p) {}
	double perimeter() const { // perimeter of polygon
		double total = 0.0;
		for (size_t i = 0; i < p.size(); ++i)
			total += (p[(i + 1) % p.size()] - p[i]).norm();
		return total;
	}
	double area() const { // area of polygon
		double total = 0.0;
		for (size_t i = 0; i < p.size(); ++i)
			total += p[i].perp().dot(p[(i + 1) % p.size()]);
		return fabs(total) / 2.0;
	}
	bool isCCW() const { // is polygon a counterclockwise convex polygon?
		if (p.size() < 3) return false;
		for (size_t i = 0; i < p.size(); ++i)
			if (ccw(p[i], p[(i + 1) % p.size()], p[(i + 2) % p.size()]) < EPS) return false;
		return true;
	}
	bool isConvex() const { // is polygon convex
		if (p.size() < 3) return false;
		bool direction = ccw(p[0], p[1], p[2]) >= EPS;
		for (size_t i = 1; i < p.size(); ++i)
			if ((ccw(p[i], p[(i + 1) % p.size()], p[(i + 2) % p.size()]) >= EPS) != direction)
				return false;
		return true;
	}
	

};

// comparison by polar coordinate with reference to pivot
struct polarCompare {
	point pivot;
	polarCompare(point _pivot = point()): pivot(_pivot) {}
	bool operator()(point a, point b) {
		if (collinear(pivot, a, b)) return (a - pivot).sqnorm() < (b - pivot).sqnorm();
		return (a - pivot).angle() < (b - pivot).angle();
	}
};

// graham scan
vector<point> convexHull(const vector<point>& points) {
	if (points.size() <= 2) return points; // special case
	
	vector<point> p(points);
	int id = 0, n = p.size();
	for (int i = 1; i < n; ++i)
		if (p[i].y < p[id].y) id = i;
		else if (p[i].y == p[id].y && p[i].x > p[id].x) id = i;
		
	// put pivot in front
	point tmp = p[id]; p[id] = p[0]; p[0] = tmp;
	sort(++p.begin(), p.end(), polarCompare(p[0]));
	
	//for (int i = 0; i < n; ++i) printf("-- %lld %lld\n", p[i].x, p[i].y);
	p.push_back(p[0]); // sentinel point

	int m = 1;
	for (int i = 2; i < n + 1; ++i) {
		while (m && ccw(p[m - 1], p[m], p[i]) <= 0) { --m; }
		++m;
		tmp = p[m]; p[m] = p[i]; p[i] = tmp;
	}
	p.erase(p.begin() + m, p.end());
	return p;
}



// perform the convex hull algorithm.
void example5() {
	vector<point> data;
	data.push_back(point(0.0, 0.0));
	data.push_back(point(5.0, 0.0));
	data.push_back(point(0.0, 10.0));
	data.push_back(point(4.0, 7.0));
	data.push_back(point(3.0, 2.0));
	data.push_back(point(6.0, 5.0));
	data.push_back(point(2.0, 8.0));
	
	// resulting hull is a counterclockwise convex polygon
	polygon hull = convexHull(data);
	for (size_t i = 0; i < hull.p.size(); ++i) {
//		printf("(%.3lf, %.3lf)", hull.p[i].x, hull.p[i].y);
		if (i == hull.p.size() - 1) printf("\n");
		else printf(", ");
	}
}


map<pair<int, int> , int> m;
int ans[3005], x[3005], y[3005], N, TC;
bool done[3005];
int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d", &TC);
	for (int t = 1; t <= TC; ++t) {
		scanf("%d", &N);
		m.clear();
		for (int i = 0; i < N; ++i) {
			scanf("%d%d", &x[i], &y[i]);
			m[make_pair(x[i], y[i])] = i;
			ans[i] = N-1;
		}
		for (int bs = 1; bs < (1<<N); ++bs) {
			vector<point> p;
			int cnt = 0;
			for (int k = 0; k < N; ++k) {
				if (bs & (1<<k)) p.push_back(point(x[k], y[k])), done[k] = 0;
				else ++cnt, done[k] = 1;
			}
			vector<point> ch = convexHull(p);
			for (int i = 0; i < ch.size(); ++i) {
				int k = m[make_pair(ch[i].x, ch[i].y)];
				done[k] = true;
				ans[k] = min(ans[k], cnt);
			}
			for (int i = 0; i < N; ++i) {
				if (done[i]) continue;
				for (int k = 0; k < ch.size(); ++k) {
					if (collinear(ch[k], point(x[i],y[i]), ch[(k+1)%ch.size()])) {
						ans[i] = min(ans[i], cnt);
						break;
					}
				}
			}
		}
		printf("Case #%d:\n", t);
		for (int i = 0; i < N; ++i) printf("%d\n", ans[i]);
		
	}
	return 0;
}
