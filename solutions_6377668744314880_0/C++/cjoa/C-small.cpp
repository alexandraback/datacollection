#include <iostream>

#include <cmath>

#include <vector>
#include <algorithm>

using namespace std;

typedef long long llong;

#define SZ(a) int((a).size())

#define BITCOUNT(mask) ( __builtin_popcount((mask)) )

struct Point {
   int x, y;
   Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
   bool operator==(const Point& p) const {
      return x == p.x && y == p.y;
   }
   bool operator!=(const Point& p) const {
      return !(*this == p);
   // return x != p.x || y != p.y;
   }
   bool operator<(const Point& p) const {
      return x < p.x || x == p.x && y < p.y;
   }
};


// cross product
// twice SIGNED area of triangle represented by points a, b, c
llong cross_product( Point a, Point b, Point c ) {
   return (b.x - a.x)*llong(c.y - a.y) - 
          (c.x - a.x)*llong(b.y - a.y);
}

// is point c left of the line determined by (a, b)?
bool left( Point a, Point b, Point c ) {
   return cross_product(a, b, c) > 0;
}

bool collinear( Point a, Point b, Point c ) {
   return cross_product(a, b, c) == 0;
}

// points a,b,c are collinear and c lies in segment ab
bool between( Point a, Point b, Point c ) {
   if ( !collinear(a, b, c) )
      return false;
   /* if ab vertical, check betweeness on y, else on x */
   return a.x == b.x ?
      a.y <= c.y && c.y <= b.y || a.y >= c.y && c.y >= b.y :
      a.x <= c.x && c.x <= b.x || a.x >= c.x && c.x >= b.x;
}


llong squared_dist(Point p1, Point p2) {
   return llong(p1.x-p2.x)*(p1.x-p2.x) + llong(p1.y-p2.y)*(p1.y-p2.y);
}

#define EPS (1e-9)

class Cmp {
   Point pivot;
public:
   Cmp(Point p) : pivot(p) {}
   bool operator() (Point p1, Point p2) const {
      double at1 = atan2(p1.y-pivot.y, p1.x-pivot.x);
      double at2 = atan2(p2.y-pivot.y, p2.x-pivot.x);
      return at1 < at2-EPS ||
             at1 >= at2-EPS && at1 <= at2+EPS &&
             squared_dist(p1, pivot) <
             squared_dist(p2, pivot);
   }
};

vector< Point > graham_scan(vector< Point > pts) {
   int N = int(pts.size());
   if (N <= 2) {
      if (N == 2 && pts[0] == pts[1])
         pts.erase(pts.begin()+1);
      else
      if (pts[1].y < pts[0].y ||
         (pts[1].y == pts[0].y && pts[1].x < pts[0].x))
         swap(pts[0], pts[1]);
      return pts;
   }

   // find pivot (lowest y, then x)
   int mini = 0;
   for (int i = 1; i < N; ++i)
      if (pts[i].y < pts[mini].y ||
          pts[i].y == pts[mini].y && pts[i].x < pts[mini].x)
         mini = i;
   if (mini != 0)
      swap(pts[0], pts[mini]);

   // sort points by angle (with points with equal angle further
   //  sorted by distance from P);
   sort(pts.begin()+1, pts.end(), Cmp(pts[0]));

   vector< Point > s;  // stack
   s.push_back(pts[0]);
   for (int i = 1; i < N; ++i) {
      while (s.size() >= 2 && !left(s[int(s.size())-2], s.back(), pts[i]) ||
             s.size() == 1 && s.back() == pts[i])
         s.pop_back();
      s.push_back(pts[i]);
   }

   return s;
}

int N;
vector< Point> P;

vector<int> solve() {
   vector<int> res(N, N-1);
   for (int mask = (1<<N)-1; mask > 0; --mask) {
      int ntrees_left = BITCOUNT(mask);
      if (ntrees_left <= 1) continue;
      int ntrees_cut = N - ntrees_left;
      vector< Point > Q;
      for (int i = 0; i < N; ++i) {
         if ((mask & (1<<i)) == 0) continue;
         Q.push_back( P[i] );
      }
/*
      bool trace = mask == 30;
      if (trace) {
         for (int j = 0; j < SZ(Q); ++j) {
            cerr << Q[j].x << ' ' << Q[j].y << endl;
         }
      }
*/
      vector< Point > C = graham_scan(Q);
/*
      if (trace) {
         for (int j = 0; j < SZ(C); ++j) {
            cerr << C[j].x << ' ' << C[j].y << endl;
         }
      }
*/
      for (int i = 0; i < N; ++i) {
         if ((mask & (1<<i)) == 0) continue;
         for (int j = 1; j < SZ(C); ++j) {
            if (between(C[j-1], C[j], P[i])) {
               res[i] = min(res[i], ntrees_cut);
            }
         }
         if (between(C.back(), C.front(), P[i]))
            res[i] = min(res[i], ntrees_cut);
      }
   }
   return res;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      cin >> N;
      P = vector<Point>(N);
      for (int i = 0; i < N; ++i)
         cin >> P[i].x >> P[i].y;
      vector<int> res = solve();
      cout << "Case #" << tc << ":" << endl;
      for (int i = 0; i < N; ++i)
         cout << res[i] << endl;
   }

   return 0;
}
