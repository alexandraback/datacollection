#include <bits/stdc++.h>
#define REP(x,n)  for(int x=0;x<(int)(n);x++)
#define RREP(x,n) for(int x=(int)(n)-1;x>=0;--x)
#define FOR(x,m,n) for(int x=(int)m;x<(int)(n);x++)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))

using namespace std;
typedef long long LL;
typedef long long T;
struct Point {
	T x, y;
	Point() {}
	Point(T x, T y) : x(x), y(y) {}
	bool operator<(const Point &rhs) const { return make_pair(y, x) < make_pair(rhs.y, rhs.x); }
	bool operator==(const Point &rhs) const { return make_pair(y, x) == make_pair(rhs.y, rhs.x); }
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
T cross(const Point &O, const Point &A, const Point &B) {
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P) {
	int n = P.size(), k = 0;
	vector<Point> H(2 * n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}

void dostuff() {
	int N, x, y;
	scanf("%i", &N);
	vector<Point> all(N), temp;
	map<Point, int> Point_idx;
	vector<int> result(N);
	REP(i, N) {
		scanf("%i %i", &x, &y);
		all[i] = Point(x, y);
		result[i] = N + 1;
		Point_idx[all[i]] = i;
	}
	REP(mask, 1 << N) {
		vector<Point> temp;
		REP(i, N) if (1 << i & mask) {
			temp.push_back(all[i]);
		}
		int rem = N - temp.size();
		temp = convex_hull(temp);
		for (Point Point : temp) {
			if (result[Point_idx[Point]] > rem)
				result[Point_idx[Point]] = rem;
		}
	}
	REP(i, N) printf("%i\n", result[i]);
}

int main() {
	int T;
	scanf("%i", &T);
	REP(t, T) printf("Case #%i:\n", t + 1), dostuff();
}