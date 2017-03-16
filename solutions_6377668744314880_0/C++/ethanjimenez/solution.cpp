#include <stdio.h>
#include <algorithm>
using namespace std;
 
struct Point{
long long x, y; int idx;
bool operator <(Point cmp) const{
if(x == cmp.x)
return y < cmp.y;
return x < cmp.x;
}
};
 
long long Cross(Point u, Point v){ // O(1)
return u.x * v.y - v.x * u.y;
} 
 
Point P(long long x, long long y, int i){ // O(1)
Point* p = new Point;
p->x = x, p->y = y; p->idx = i;
return *p;
}
 
Point Vector(Point o, Point p){ // O(1)
return P(p.x - o.x, p.y - o.y, 0);
}
 
bool CCW(Point p, Point q, Point r){ // O(1)
return Cross(Vector(p, q), Vector(p, r)) >= 0;
}
 
vector<Point> ConvexHull(vector<Point> P){
vector<Point> U, L;
for(int i = 0; i < P.size(); i++){
while(L.size() > 1){
Point p = L[L.size() - 2];
Point q = L[L.size() - 1];
if(CCW(p, q, P[i])) break;
else L.pop_back();
}
L.push_back(P[i]);
}
if(L.size() > 1) L.pop_back();
for(int i = P.size() - 1; i >= 0; i--){
while(U.size() > 1){
Point p = U[U.size() - 2];
Point q = U[U.size() - 1];
if(CCW(p, q, P[i])) break;
else U.pop_back();
}
U.push_back(P[i]);
}
for(int i = 0; i < U.size(); i++)
L.push_back(U[i]);
return L;
}

int main() {
  int t, n, x, y;
  scanf("%d", &t);
  for (int c = 1; c <= t; ++c) {
    scanf("%d", &n);
    vector<Point> poly;
    vector<int> mins(n, 100);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &x, &y);
      poly.push_back(P(x, y, i));
    }
    sort(poly.begin(), poly.end());
    for (int i = 0; i < (1 << n); ++i) {
      int cutted_trees = 0;
      vector<Point> subset;
      for (int j = 0; j < n; ++j) {
        if (!((1 << j) & i)) {
          ++cutted_trees; continue; }
        subset.push_back(poly[j]);
      }
      vector<Point> convex = ConvexHull(subset);
      for (int j = 0; j < convex.size(); ++j)
        mins[convex[j].idx] = min(mins[convex[j].idx], cutted_trees);
    }
    printf("Case #%d:\n", c);
    for (int i = 0; i < n; ++i)
      printf("%d\n", mins[i]);
  }
  return 0;
}