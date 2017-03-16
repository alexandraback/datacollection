#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <complex>
#include <numeric>
#include <ext/numeric>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <bitset>

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ullong;
typedef long long llong;
typedef list<int> EdgeList;
typedef vector<EdgeList> AdjList;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef complex<double> P2;

#define FOR_EDGE(adj,v,it) for (EdgeList::iterator it = adj[v].begin(); \
    it != adj[v].end(); ++it)

struct Point {
  llong x,y;
  Point(){}
  Point(llong x, llong y) :x(x),y(y){}
  bool operator<(const Point& p) const {
    if (x != p.x) return x < p.x;
    else return y < p.y;
  }
  bool operator==(const Point& p) const {
    return x == p.x && y == p.y;
  }
  llong dist(const Point& o) const {
    llong dx = x-o.x;
    llong dy = y-o.y;
    return dx*dx + dy*dy;
  }
  P2 operator-(const Point& q) const {
    return P2(x - q.x, y - q.y);
  }
  P2 operator-() const {
    return P2(-x, -y);
  }
  P2 operator/(const double& u) const {
    return P2(x/u, y/u);
  }
};

template <typename T>
double X(T p);
template <typename T>
double Y(T p);
template <>
double X(Point p) {
  return p.x;
}
template <>
double Y(Point p) {
  return p.y;
}

inline llong ccw(const Point& O, const Point& A, const Point& B){
  return ((X(A)-X(O))*(Y(B)-Y(O)) - (Y(A)-Y(O))*(X(B)-X(O)));
}

inline bool in_segment(const Point& A, const Point& B, const Point& P) {
  if (ccw(A, B, P) != 0) return false;
  if (A.x != B.x) {
    if (A.x <= P.x && P.x <= B.x) {
      return true;
    }
    if (A.x >= P.x && P.x >= B.x) {
      return true;
    }
  } else {
    if (A.y <= P.y && P.y <= B.y) {
      return true;
    }
    if (A.y >= P.y && P.y >= B.y) {
      return true;
    }
  }
  return false;
}

vector<Point> convexHull(vector<Point>& included){
  vector<Point> hull;
  
  sort(included.begin(), included.end());
  hull.resize(2*included.size());
  //   Get lower hull
  int k = 0;
  for (int i = 0; i < included.size(); ++i) {
    while (k >= 2 && ccw(hull[k-2], hull[k-1], included[i]) <= 0) --k;
    hull[k++] = included[i];
  }
  // Get upper hull
  for (int i = included.size()-2, t = k+1; i >= 0; --i) {
    while (k >= t && ccw(hull[k-2], hull[k-1], included[i]) <= 0) --k;
    hull[k++] = included[i];
  }
  // note that hull[0] == hull[k-1]
  hull.resize(k);
  return hull;
}

int main() {
  int n_cases;
  scanf("%d", &n_cases);

  Point arr[16];
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%lld %lld", &arr[i].x, &arr[i].y);
    }
    if (n <= 3) {
      printf("Case #%d:\n", ctr+1);
      for (int i = 0; i < n; ++i) puts("0");
      continue;
    }

    int ans[16];
    for (int i = 0; i < n; ++i) { ans[i] = n-1; };
    for (int i = 1; i < (1 << n); ++i) {
      vector<Point> P;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          P.push_back(arr[j]);
        }
      }

      vector<Point> hull = convexHull(P);

      bool incl[16];
      for (int j = 0; j < n; ++j) incl[j] = false;
      for (int u = 0; u < n; ++u) {
        for (int j = 0; j  < hull.size(); ++j) {
          if (arr[u] == hull[j]) {
            incl[u] = true;
            break;
          }
        }
        if (incl[u]) continue;
        for (int j = 0; j + 1 < hull.size(); ++j) {
          if (in_segment(hull[j], hull[j+1], arr[u])) {
            incl[u] = true;
            break;
          }
        }
      }
      #ifdef DEBUG
      for (int j = 0; j < hull.size(); ++j) {
        printf("(%lld, %lld) ", hull[j].x, hull[j].y);
      }
      puts("");
      for (int j = 0; j < n; ++j) {
        printf("(%lld, %lld)=%d ", arr[j].x, arr[j].y, incl[j]);
      }
      if (i == (1 << n) - 1) {
        printf("%lld %d\n", ccw(hull[0], hull[1], arr[1]), in_segment(hull[0], hull[1], arr[1]));
      }
      puts("=======");
      #endif

      int delta = n-__builtin_popcount(i);

      for (int j = 0; j < n; ++j) {
        if (incl[j]) {
          ans[j] = min(ans[j], delta);
        }
      }

    }

    printf("Case #%d:\n", ctr+1);
    for (int i = 0; i < n; ++i) {
      printf("%d\n", ans[i]);
    }
  }
  
  return 0;
}
