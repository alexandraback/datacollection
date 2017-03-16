#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

#pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

const double EPS(1e-8);
const double PI = acos(-1.0);

#pragma region 基本要素(struct,typedef)

typedef ll T;

struct P {
	T x, y;
	P() : x(0), y(0) {}
	P(const T& x, const T& y) : x(x), y(y) {}
	P operator+(const P &a)const { return P(x + a.x, y + a.y); }
	P& operator+=(const P &a) { x += a.x; y += a.y; return *this; }
	P operator-(const P &a)const { return P(x - a.x, y - a.y); }
	P& operator-=(const P &a) { x -= a.x; y -= a.y; return *this; }
	P operator*(const T a)const { return P(a*x, a*y); }
	P& operator*=(const T a) { x *= a; y *= a; return *this; }
	P operator/(const T a)const { return P(x / a, y / a); }
	P& operator/=(const T a) { x /= a; y /= a; return *this; }

	//比較用
	bool operator<(const P &a)const { return (x != a.x) ? (x < a.x) : (y < a.y); }
	bool operator==(const P &a)const { return tie(x, y) == tie(a.x, a.y); }
};

struct S {
	P a, b;
	S() {}
	S(const P& a, const P& b) : a(a), b(b) {}
};

struct line {
	P a, b;
	line() : a(P()), b(P()) {}
	line(const P& a, const P& b) : a(a), b(b) {}
};

struct circle {
	P c;
	T r;
	circle(){}
	circle(const P &c, T& r) : c(c), r(r) {}
};

#pragma endregion

#pragma region 基本要素(関数)

T SQ(T x){ return x*x; }
T dist2(const P &a, const P &b){ return SQ(a.x - b.x) + SQ(a.y - b.y); }
T abs2(const P& p){ return SQ(p.x) + SQ(p.y); }
T dot(const P& a, const P& b){ return a.x*b.x + a.y*b.y; }
T cross(const P& a, const P& b){ return a.x*b.y - a.y*b.x; }
double arg(const P &a){ double t = atan2(a.y, a.x); return t<0 ? t + 2 * PI : t; }

enum { CCW = 1, CW = -1, ON = 0 };
int ccw(const P &a, P b, P c){
	b -= a; c -= a;
	T rdir = cross(b, c);

	if (rdir > 0) return CCW; //cがabより上(反時計周り)
	if (rdir < 0) return CW; // cがabより下(時計周り)
	return ON; // a,b,cが一直線上
}

#pragma endregion

#pragma region 入出力

std::ostream& operator<<(std::ostream& os, const P& point){ return (os << '(' << point.x << ',' << point.y << ')'); }
std::ostream& operator<<(std::ostream& os, const S& seg){ return (os << '{' << seg.a << ',' << seg.b << '}'); }
std::istream& operator>>(std::istream& is, P& point){ return (is >> point.x >> point.y); }

#pragma endregion

//凸包
vector<P> convex_hull(vector<P>& ps) {
	if (sz(ps) <= 2) return ps;
	int n = ps.size(), k = 0;
	sort(ps.begin(), ps.end());
	vector<P> ch(2 * n);
	for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) < 0) --k;

	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) // upper-hull
		while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) < 0) --k;

	ch.resize(k - 1);

	return ch;
}

void P_sort(vector<P>& vp){
	//反時計回りにsortする
	//また，3時の方向をx軸とする
	auto g = [](const P& p) {
		if (p.x == 0 && p.y == 0) return 0;
		if (p.x > 0 && p.y >= 0) return 1;
		if (p.x <= 0 && p.y > 0) return 2;
		if (p.x < 0 && p.y <= 0) return 3;
		return 4;

	};
	auto f = [&g](const P&l, const P& r) {
		int gl = g(l);
		int gr = g(r);
		if (gl != gr) return gl < gr;
		P o;
		int c = ccw(o, l, r);
		return c > 0;
	};

	sort(vp.begin(), vp.end(), f);
}

void P_sort_test(){
	vector<P> vp = {
		P(0, 0),
		P(1, 0),
		P(1, 0),
		P(1, 1),
		P(0, 1),
		P(-1, 1),
		P(-1, 0),
		P(-1, -1),
		P(0, -1),
		P(1, -1),
	};
	auto cp = vp;
	random_shuffle(vp.begin(), vp.end());
	P_sort(vp);
	assert(cp == vp);
}

vector<int> solve(){
	int n; cin >> n;
	vector<P> ps(n);
	FOR(i, n) cin >> ps[i];

	vector<int> anses(n, n);

	const P o;
	FOR(i, n){
		vector<P> u;
		FOR(j, n){
			if(i != j) u.push_back(ps[j] - ps[i]);
		}
		P_sort(u);
		FOR(x, n-1) u.push_back(u[x]);
		int r = 0;
		int ans = n-1;
		FOR(l, n-1){
			if (r < l) r = l;
			while (r < l + n-1) {
				if (ccw(o, u[l], u[r]) >= 0)
					r++;
				else
					break;
			}
			ans = min(ans, min(r - l, n-1 - (r - l)));
		}
		anses[i] = ans;
	}
	return anses;
}

int main() {
	P_sort_test();

	int t; cin >> t;
	FOR(i, t){
		auto ans = solve();
		printf("Case #%d:\n", i+1);
		for (auto x : ans) printf("%d\n", x);
	}
	return 0;
}