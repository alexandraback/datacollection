#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 

#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Vector
{
	double x, y;
	
	Vector(double a = 0.0, double b = 0.0): x(a), y(b) { }
	Vector(const Vector & v): x(v.x), y(v.y) { }

	Vector & operator=(const Vector & v) { x = v.x; y = v.y; return *this; }
	Vector operator+(const Vector & v) const { return Vector(x + v.x, y + v.y); }
	Vector & operator+=(const Vector & v) { x += v.x; y += v.y; return *this; }
	Vector operator-(const Vector & v) const { return Vector(x - v.x, y - v.y); }
	Vector & operator-=(const Vector & v) { x -= v.x; y -= v.y; return *this; }
	Vector operator*(double n) const { return Vector(x * n, y * n); }
	Vector & operator*=(double n) { x *= n; y *= n; return *this; }
	Vector operator/(double n) const { return Vector(x / n, y / n); }
	Vector & operator/=(double n) { x /= n; y /= n; return *this; }

	bool operator==(const Vector & v) const { return EQ(x, v.x) && EQ(y, v.y); }
	bool operator!=(const Vector & v) const { return !EQ(x, v.x) || !EQ(y, v.y); }
	bool operator<(const Vector & v) const { return x < v.x || (EQ(x, v.x) && y < v.y); }

	double size() const { return sqrt(x*x + y*y); }
	double size2() const { return x*x + y*y; }
	double angle() const { return atan2(y, x); }
};

inline double dot_product(const Vector & v1, const Vector & v2) 
	{ return v1.x * v2.x + v1.y * v2.y; }

inline double cross_product(const Vector & v1, const Vector & v2) 
	{ return v1.x * v2.y - v1.y * v2.x; }

inline double direction(const Vector & segment1, const Vector & segment2, const Vector & point) 
	{ return cross_product(point - segment1, segment2 - segment1); }

void convex_hull(vector<Vector> & points, vector<Vector> & hull)
{
	sort(points.begin(), points.end());
	vector<Vector> top, bot;
	for (int i = 0; i < points.size(); ++i)
	{
		while (top.size() >= 2 && direction(top[top.size()-2], points[i], top[top.size()-1]) < 0)
			top.pop_back();
		top.push_back(points[i]);
		while (bot.size() >= 2 && direction(bot[bot.size()-2], points[i], bot[bot.size()-1]) > 0)
			bot.pop_back();
		bot.push_back(points[i]);
	}
	reverse(bot.begin(), bot.end());
	hull = top;
	if (bot.size() > 2) hull.insert(hull.end(), bot.begin()+1, bot.end()-1);
}

const int MAX = 3007;
int N;

void Solve(int tc)
{
	scanf("%d", &N);
	vector<Vector> vs(N);
	REP(i, N) {
		scanf("%lf%lf", &vs[i].x, &vs[i].y);
	}

	printf("Case #%d: ", tc);
	REP(i, N) {
		int best = N;
		for (int state = 0; state < two(N); ++state) {
			vector<Vector> vs2, hull;
			REP(j, N)
				if (test(state, j))
					vs2.push_back(vs[j]);
			convex_hull(vs2, hull);

			bool ok = false;
			REP(j, hull.size())
				if (vs[i] == hull[j])
					ok = true;
			if (ok)
				best = min(best, N-ones(state));
		}
		printf("%d\n", best);
	}

}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) {
		cerr << "Test case: " << tc << endl;
		Solve(tc);
	}

	return 0;
}