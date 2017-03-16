#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

// Convex hull code from http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
// Licensed under CC-Attribution-ShareAlike

typedef long long coord_t;         // coordinate type

struct Point {
	coord_t x, y;

	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}

// ---- MY CODE ----

bool contains(vector<Point> v, coord_t x, coord_t y) {
  for (int i = 0; i < v.size(); ++i)
    if (v[i].x == x && v[i].y == y)
      return true;
  return false;
}

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) scanf("%Ld %Ld", &pts[i].x, &pts[i].y);

    cout << "Case #" << tt << ":\n";

    vector<Point> ch = convex_hull(pts);

    for (int i = 0; i < n; ++i) {
      if (contains(ch, pts[i].x, pts[i].y)) {
        printf("0\n");
        continue;
      }

      int best = n-1;

      for (int set = 1; set < (1 << n); ++set) {
        if (set & (1 << i)) continue;  // can't remove current point

        int removed = 0;
        vector<Point> npts;
        for (int j = 0; j < n; ++j) {
          if (i != j && (set & (1 << j))) {
            ++removed;
          } else {
            Point p; p.x = pts[j].x; p.y = pts[j].y;
            npts.push_back(p);
          }
        }

        if (removed > best) continue;

        vector<Point> nch = convex_hull(npts);

        if (contains(nch, pts[i].x, pts[i].y))
          if (removed < best) best = removed;
      }

      printf("%d\n", best);
    }

  }
}
