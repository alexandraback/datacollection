#include <bits/stdc++.h>

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

#define REP(i, a, b) for(int i = (a); i < int(b); ++i)
#define rep(i, n) REP(i, 0, n)
#define ALL(x) begin(x), end(x)

template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

constexpr double EPS = 1e-9;

struct point {
	double x, y;
	explicit point(double x_ = 0.0, double y_ = 0.0):x(x_), y(y_) {}
	point(const point &p):x(p.x), y(p.y) {}

	point operator+(const point &p) const {
		return point(x + p.x, y + p.y);
	}

	point operator-(const point &p) const {
		return point(x - p.x, y - p.y);
	}

	point operator*(double s) const {
		return point(x * s, y * s);
	}

	point operator*(const point &p) const {
		return point(x * p.x - y * p.y, x * p.y + y * p.x);
	}

	point operator/(double s) const {
		return point(x / s, y / s);
	}

	bool operator<(const point &p) const {
		return x + EPS < p.x || (abs(x - p.x) < EPS && y + EPS < p.y);
	}

	bool operator==(const point &p) const {
		return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
	}
};

point rotate90(const point &p) {
	return point(-p.y, p.x);
}

point rotate(const point &p, double theta) {
	const double s = sin(theta), c = cos(theta);
	return point(c * p.x - s * p.y, s * p.x + c * p.y);
}

double angle(const point &p) {
	return atan2(p.y, p.x);
}

double norm(const point &p) {
	return p.x * p.x + p.y * p.y;
}

double abs(const point &p) {
	return sqrt(norm(p));
}

double dot(const point &a, const point &b) {
	return a.x * b.x + a.y * b.y;
}

double cross(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}

struct line {
	point a, b;
	line(const point &a_, const point &b_):a(a_), b(b_){}
};

struct segment {
	point a, b;
	segment(const point &a_, const point &b_):a(a_), b(b_){}
};

struct circle {
	point c;
	double r;
	circle(const point &c_, const double &r_):c(c_), r(r_){}
};

typedef vector<point> polygon;

int ccw(const point &a, point b, point c) {
	b = b - a;
	c = c - a;
	const double tmp = cross(b, c);
	if(tmp > EPS) return 1; // ccw
	if(tmp < -EPS) return -1; // cw
	if(dot(b, c) < 0) return 2; // c, a, b 順に一直線上
	if(norm(b) < norm(c)) return -2; // a, b, c 順に一直線上
	return 0; //a, c, b 順で一直線上
}

point project(const line &l, const point &p) {
	const point dif = l.b - l.a;
	const double tmp = dot(p - l.a, dif) / norm(dif);
	return l.a + dif * tmp;
}

bool intersect(const line &l, const line &m) {
	return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS;
}

bool intersect(const line &l, const segment &s) {
	return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;
}

bool intersect(const line &l, const point &p) {
	return abs(ccw(l.a, l.b, p)) != 1;
}

bool intersect(const segment &s, const segment &t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0
		&& ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

bool intersect(const segment &s, const point &p) {
	return ccw(s.a, s.b, p) == 0;
}

bool intersect(const circle &c, const point &p) {
	return abs(c.c - p) < c.r + EPS;
}

bool intersect(const circle &c, const circle &d) {
	return abs(c.c - d.c) < c.r + d.r + EPS && abs(c.c - d.c) + EPS > abs(c.r - d.r);
}

double dist(const line &l, const point &p) {
	return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);
}

double dist(const line &l, const line &m) {
	return intersect(l, m) ? 0 : dist(l, m.a);
}

double dist(const line &l, const segment &s) {
	return intersect(l, s) ? 0 : min(dist(l, s.a), dist(l, s.b));
}

double dist(const segment &s, const point &p) {
	if(dot(s.b - s.a, p - s.a) < 0) return abs(p - s.a);
	if(dot(s.a - s.b, p - s.b) < 0) return abs(p - s.b);
	return dist(line(s.a, s.b), p);
}

double dist(const segment &s, const segment &t) {
	if(intersect(s, t)) return 0;
	return min({dist(s, t.a), dist(s, t.b), dist(t, s.a), dist(t, s.b)});
}

double dist(const point &a, const point &b) {
	return abs(a - b);
}

bool intersect(const circle &c, const segment &s) {
	return dist(s, c.c) < c.r + EPS;
}

point crosspoint(const line &l, const line &m) {
	const double tmp = cross(l.b - l.a, m.b - m.a);
	if(abs(tmp) < EPS) return l.a; // 平行
	return m.a + (m.b - m.a) * (cross(l.b - l.a, l.a - m.a) / tmp);
}

// 先にintersectで交差判定をすること
point crosspoint(const segment &s, const segment &t) {
	const double tmp = cross(s.b - s.a, t.b - t.a);
	if(abs(tmp) < EPS) { // 一直線上
		if(intersect(s, t.a)) return t.a;
		if(intersect(s, t.b)) return t.b;
		if(intersect(t, s.a)) return s.a;
		return s.b;
	}
	return t.a + (t.b - t.a) * (cross(s.b - s.a, s.b - t.a) / tmp);
}

//先に，intersectを用いて交差判定を行うこと
vector<point> crosspoint(const circle &c, const circle &d) {
	vector<point> res;
	if(abs(c.c - d.c) < EPS) return res; // 中心の座標が同じ

	const double tmp = abs(c.c - d.c);
	const double rc = (tmp * tmp + c.r * c.r - d.r * d.r) / (tmp + tmp);
	const double rs = sqrt(c.r * c.r - rc * rc);
	const point diff = (d.c - c.c) / tmp;
	res.emplace_back(c.c + diff * point(rc, rs));
	res.emplace_back(c.c + diff * point(rc, -rs));
	return res;
}

vector<point> crosspoint(const circle &c, const line &l) {
	vector<point> res;
	const point h = project(l, c.c);
	const double d = abs(h - c.c);
	if(d > c.r + EPS) {
		// nothing
	}
	else if(d > c.r - EPS) {
		res.emplace_back(h);
	}
	else if(d <= c.r - EPS) {
		point v = l.b - l.a;
		v = v * sqrt(c.r * c.r - d * d) / abs(v);
		res.emplace_back(h - v);
		res.emplace_back(h + v);
	}

	return res;
}

vector<point> crosspoint(const circle &c, const segment &s) {
	vector<point> res;
	vector<point> tmp = crosspoint(c, line(s.a, s.b));
	for(const auto &p : tmp) {
		if(intersect(s, p)) res.emplace_back(p);
	}
	return res;
}

double rad(point a, point b, const point &base = point(0, 0)) {
	a = a - base;
	b = b - base;
	const int c = ccw(point(0, 0), a, b);
	if(abs(c) != 1) return 0;
	return c * acos(dot(a, b) / (abs(a) * abs(b)));
}

double area_triangle(const point &a, const point &b, const point &c) {
	return abs(cross(a - c, b - c)) * 0.5;
}

double area(const polygon &P) {
	const int n = P.size();
	if(n < 3) return 0;
	if(n == 3) return area_triangle(P[0], P[1], P[2]);

	double res = 0.0;
	point prev = P.back();

	for(const auto &curr : P) {
		res += cross(prev, curr);
		prev = curr;
	}
	return abs(res) * 0.5;
}

double common_area(const circle &a, const circle &b) {
    if(!intersect(a, b)) return (intersect(a, b.c) || intersect(b, a.c) ? min(a.r * a.r, b.r * b.r) * M_PI : 0.0);
    const auto cp = crosspoint(a, b);
    return a.r * a.r * abs(rad(cp.front(), b.c, a.c)) + b.r * b.r * abs(rad(cp.front(), a.c, b.c)) - abs(cross(a.c - cp.front(), b.c - cp.front()));
}

double common_area(circle c, point a, point b) {
    a = a - c.c;
    b = b - c.c;
    c.c = c.c - c.c;

    const auto cp = crosspoint(c, line(a, b));
    if(cp.size() == 0) return c.r * c.r * rad(a, b) / 2;

    const bool b1 = abs(a) > c.r + EPS;
    const bool b2 = abs(b) > c.r + EPS;

    if(b1 && b2) {
        if(dot(a - cp.front(), b - cp.front()) < EPS && dot(a - cp.back(), b - cp.back()) < EPS) {
            return (c.r * c.r * (rad(a, b) - rad(cp.front(), cp.back()))
                    + cross(cp.front(), cp.back())) / 2;
        }
        else {
            return c.r * c.r * rad(a, b) / 2;
        }
    }
    else if(b1) {
        return (c.r * c.r * rad(a, cp.front()) + cross(cp.front(), b)) / 2;
    }
    else if(b2) {
        return (c.r * c.r * rad(cp.back(), b) + cross(a, cp.back())) / 2;
    }
    else {
        return cross(a, b) / 2;
    }
}

double common_area(const circle &c, const polygon &P) {
    double res = 0.0;
    point prev = P.back();

    for(const auto &curr : P) {
        res += common_area(c, prev, curr);
        prev = curr;
    }

    return abs(res);
}

// L.aからL.bの方向を見た場合に，点aが左側に来る．
line bisector(const point &a, const point &b) {
	return line(point((a.x - a.y + b.x + b.y) / 2.0, (a.y + a.x + b.y - b.x) / 2.0),
				point((a.x + a.y + b.x - b.y) / 2.0, (a.y - a.x + b.y + b.x) / 2.0));
}

// 点集合 pointsの凸包を求める．
polygon convex_hull(vector<point> points) {
	const int n = points.size();
	if(n <= 3) return points;

	sort(points.begin(), points.end());
	int k = 0;
	polygon res;
	res.resize(2 * n);
	for(int i = 0; i < n; res[k++] = points[i++]) {
		while(k >= 2 && ccw(res[k - 2], res[k - 1], points[i]) <= 0) --k;
	}

	const int t = k + 1;
	for(int i = n - 2; i >= 0; res[k++] = points[i--]) {
		while(k >= t && ccw(res[k - 2], res[k - 1], points[i]) <= 0) --k;
	}

	res.resize(k - 1);
	return res;
}

// L.aからL.bを向いた時の左側を残して切断する．
polygon convex_cut(const polygon &P, const line &l) {
	polygon res;
	point prev = P.back();
	int pc = ccw(l.a, l.b, prev);

	for(const auto &curr : P) {
		const int cc = ccw(l.a, l.b, curr);

		if(pc != -1) {
			res.emplace_back(prev);
		}
		if(pc * cc < 0) {
			res.emplace_back(crosspoint(l, line(prev, curr)));
		}

		prev = curr;
		pc = cc;
	}

	return res;
}

vector<point> tangent(const circle &c, const point &p) {
	const double x = norm(p - c.c);
	double d = x - c.r * c.r;
	if(d < -EPS) return vector<point>();
	d = max(d, 0.0);
	const point q1 = (p - c.c) * (c.r * c.r / x);
	const point q2 = rotate90((p - c.c) * (-c.r * sqrt(d) / x));
	vector<point> res;
	res.emplace_back(c.c + q1 - q2);
	res.emplace_back(c.c + q1 + q2);
	return res;
}

vector<line> tangent(const circle &a, const circle &b) {
	vector<line> res;
	if(abs(a.r - b.r) < EPS) {
		point dir = b.c - a.c;
		dir = rotate90(dir * (a.r / abs(dir)));
		res.emplace_back(a.c + dir, b.c + dir);
		res.emplace_back(a.c - dir, b.c - dir);
	}
	else {
		point p = a.c * (-b.r) + b.c * a.r;
		p = p * (1.0 / (a.r - b.r));
		vector<point> ps = tangent(a, p), qs = tangent(b, p);
		for(unsigned i = 0; i < min(ps.size(), qs.size()); ++i) {
			res.emplace_back(ps[i], qs[i]);
		}
	}

	point p = a.c * b.r + b.c * a.r;
	p = p * (1.0 / (a.r + b.r));
	vector<point> ps = tangent(a, p), qs = tangent(b, p);
	for(unsigned i = 0; i < min(ps.size(), qs.size()); ++i) {
		res.emplace_back(ps[i], qs[i]);
	}

	return res;
}

// 三角形と点の包含関係，境界は含む．
// 含まない場合は == -1を <= 0とする．
bool contain_triangle(const polygon &triangle, const point &p) {
	const int d1 = ccw(p, triangle[0], triangle[1]);
	const int d2 = ccw(p, triangle[1], triangle[2]);
	const int d3 = ccw(p, triangle[2], triangle[0]);
	return !(d1 * d2 == -1 || d2 * d3 == -1 || d3 * d1 == -1);
}

int sign(double d) {
	return d > EPS ? 1 : d < -EPS ? -1 : 0;
}

// 原点を始点とするベクトルa, b, cについて，
// cが「aからbへ反時計回りで回る角」の内部・辺上・外部のどこにあるか
// + : 内部
// 0 : 辺上 or A = B
// - : 外部
int judge(const point &a, const point &b, const point &c) {
	return sign(cross(a, c)) - sign(cross(b, c)) - sign(cross(a, b));
}

// 多角形と点の包含関係．境界を含む．
bool contain(const polygon &P, const point &p) {
	bool res = false;
	point v1 = P.back() - p;

	for(const auto &curr : P) {
		point v2 = curr - p;

		if(v1.y > v2.y) swap(v1, v2);
		if(v1.y < EPS && EPS < v2.y && cross(v1, v2) > EPS) res = !res;
		if(abs(cross(v1, v2)) < EPS && dot(v1, v2) < EPS) return true;
		// 境界を含まないなら，falseにする．
	}

	return res;
}

// 多角形と線分の包含関係．境界を含む．
bool contain(const polygon &p, const segment &s) {
	const int n = p.size();
	if(!contain(p, s.a + (s.b - s.a) * 0.001)) return false;
	if(!contain(p, s.b + (s.a - s.b) * 0.001)) return false;

	for(int i = 0; i < n; ++i) {
		const auto &prev = p[(i - 1 + n) % n];
		const auto &curr = p[i];
		const auto &next = p[(i + 1) % n];
		if(intersect(s, segment(curr, next))) return false;
		if(intersect(s, curr)) {
			if(judge(prev - curr, next - curr, s.a - curr) > 1) return false;
			if(judge(prev - curr, next - curr, s.b - curr) > 1) return false;
		}
	}

	return true;
}

// 凸多角形と点の包含関係
bool contain_convex(const polygon &c, const point &g, const point &p) {
	const int n = c.size();

	int L = 0, R = n;
	while(L + 1 < R) {
		const int M = (L + R) / 2;
		if(judge(c[L] - g, c[M] - g, p - g) >= 0) {
			R = M;
		}
		else {
			L = M;
		}
	}

	return contain_triangle({g, c[L], c[(L + 1) % n]}, p);
}

struct edge {
	int to;
	double cost;
	edge(int to_, double cost_):to(to_), cost(cost_) {}
};

void merge(vector<segment> &segments) {
    for(int i = 0; i < static_cast<int>(segments.size());) {
        const auto &s1 = segments[i];
        bool ok = true;
        for(int j = i + 1; j < static_cast<int>(segments.size()); ++j) {
            const auto &s2 = segments[j];

            if(intersect(s1, s2) && abs(cross(s1.a - s1.b, s2.a - s2.b)) < EPS) {
				const auto a = min({s1.a, s1.b, s2.a, s2.b});
				const auto b = max({s1.a, s1.b, s2.a, s2.b});
                segments.emplace_back(a, b);

                segments.erase(segments.begin() + j);
                segments.erase(segments.begin() + i);
                ok = false;
                break;
            }
        }
        if(ok) ++i;
    }
}

inline bool check(const polygon &P, const point &p) {
	point prev = P.back();
	for(const auto &current : P) {
		if(current == p) return true;
		if(intersect(segment(prev, current), p)) return true;
		prev = current;
	}
	return false;
}

vector<vector<edge>> arrangement(vector<segment> &segments, vector<point> &points) {
	merge(segments);
	const int n = segments.size();
	points.clear();

	for(int i = 0; i < n; ++i) {
		const auto &s1 = segments[i];
		points.emplace_back(s1.a);
		points.emplace_back(s1.b);

		for(int j = i + 1; j < n; ++j) {
			const auto &s2 = segments[j];
			if(intersect(s1, s2)) {
				points.emplace_back(crosspoint(s1, s2));
			}
		}
	}

	sort(points.begin(), points.end());
	points.erase(unique(points.begin(), points.end()), points.end());

	const int V = points.size();
	vector<vector<edge>> G(V);

	for(const auto &s : segments) {
		vector<pair<double, int>> vs;
		for(int i = 0; i < V; ++i) {
			if(intersect(s, points[i])) {
				vs.emplace_back(abs(s.a - points[i]), i);
			}
		}

		sort(vs.begin(), vs.end());
		for(int i = 1; i < static_cast<int>(vs.size()); ++i) {
			const int v = vs[i].second;
			const int u = vs[i - 1].second;
			const double d = vs[i].first - vs[i - 1].first;
			G[v].emplace_back(u, d);
			G[u].emplace_back(v, d);
		}
	}

	return G;
}


string solve() {
	int n;
	cin >> n;

	vector<point> forest;
	forest.reserve(n);

	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		forest.emplace_back(x, y);
	}

	vector<int> ans(n, n - 1);
	for(int i = 1; i < (1 << n); ++i) {
		const int num = __builtin_popcount(i);
		vector<point> points;
		points.reserve(num);

		for(int j = 0; j < n; ++j) {
			if((i >> j) & 1) {
				points.emplace_back(forest[j]);
			}
		}

		const auto P = convex_hull(points);
		for(int j = 0; j < n; ++j) {
			if(check(P, forest[j])) {
				chmin(ans[j], n - num);
			}
		}
	}
	ostringstream oss;
	for(int i = 0; i < n; ++i) {
		oss << '\n' << ans[i];
	}
	return oss.str();
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t) {
		const auto ans = solve();
		cout << "Case #" << t << ": " << ans << "\n";
	}

	return EXIT_SUCCESS;
}
