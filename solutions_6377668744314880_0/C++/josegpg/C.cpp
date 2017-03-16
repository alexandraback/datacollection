#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>

using namespace std;

#define ri(X) scanf("%d", &(X))
#define pi(X) printf("%d", (X))
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define lint long long
#define pii pair<int,int>
#define inf 1e9
#define linf 1e18
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define uni(X) X.erase(unique(X.begin(), X.end()), X.end());
#define pct(X) __builtin_popcount(X)

typedef int coord_t;         // coordinate type 
typedef long long coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2 
struct Point { 
  public: 
	int x, y; 
  Point (int _x, int _y){ 
    x = _x; 
    y = _y; 
  } 
  Point(){ 
    x = 0; 
    y = 0; 
  } 
	bool operator <(const Point &p) const { 
		return x < p.x || (x == p.x && y < p.y); 
	} 
	bool operator ==(const Point &p) const { 
		return (x == p.x && y == p.y); 
	} 
	 
}; 

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product. 
// Returns a positive value, if OAB makes a counter-clockwise turn, 
// negative for clockwise turn, and zero if the points are collinear. 
coord2_t cross(const Point &O, const Point &A, const Point &B){ 
	return (A.x - O.x) * (coord2_t)(B.y - O.y) - (A.y - O.y) * (coord2_t)(B.x - O.x); 
} 

vector<Point> convex_hull(vector<Point> P){ 
	int n = P.size(), k = 0; 
	vector<Point> H(2*n); 
	// Sort points lexicographically 
	sort(P.begin(), P.end()); 
	// Build lower hull 
	for (int i = 0; i < n; i++) { 
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

int t, n, res[3500];
Point p[3500];

vector<Point> construct(int mask) {
  vector<Point> res;
  for (int i = 0; i < n; i++) {
    if ((mask & (1<<i)) > 0) res.pb(p[i]);
  }
  return res;
}

int main(){
  ri(t);
  for (int T = 1; T <= t; T++) {
    ri(n);
    for (int i = 0; i < n; i++) res[i] = n;
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    int all = (1 << n), bcount;
    for (int i = 0; i < all; i++) {
      bcount = pct(i);
      vector<Point> cur = construct(i), ch;
      ch = convex_hull(cur);
      for (int k = 0; k < ch.size(); k++) {
        for (int j = 0; j < n; j++) if (p[j]==ch[k]) res[j] = min(res[j], n-bcount);
      }
    }
    
    printf("Case #%d:\n", T);
    for (int i = 0; i < n; i++) printf("%d\n", res[i]);
  }
  
  return 0;
}
