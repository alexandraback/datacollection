#include <cstdio>
#include <algorithm>
#include <assert.h>
#include <map>
using namespace std;

typedef long long T; const T EPS = 0;
typedef pair<T,T> Point;
#define st first
#define nd second

const int MAXN = 20;

// Convex Hull stolen from young Maciek Wawro. He might currently be ashamed of
// this code, though he shouldn't since it seems to work.
int N;                //IN: Liczba punktów
Point points[MAXN];   //IN: Punkty - psute! (sort)
int H;                //OUT:Wielkość otoczki
Point hull[MAXN+5];   //OUT:Kolejne punkty w kolejności CCW

inline bool ccw(Point& a, Point& b, Point& c){
  T A[] = {a.st-b.st,a.nd-b.nd,b.st-c.st,b.nd-c.nd};
  T det = A[0]*A[3] - A[1]*A[2];
  return det>=-EPS;
}; 

inline void addPoint(int i){
  while((H > 1) && (!ccw(hull[H-2], hull[H-1], points[i])))H--;
  hull[H++] = points[i];  
}

void computeHull(){
  int d = 0;
  sort(points, points+N);
  H = 0;                                       
  for (int i = 0; i < N; i++) addPoint(i);
  if(N < 2) return;
  for (int i = N - 2; i >= 0; i--) addPoint(i);  
  H--;
}

int main() {
  /*
  N = 7;
  points[0] = {0, 0};
  points[1] = {2, 0};
  points[2] = {2, 2};
  points[3] = {1, 3};
  points[4] = {0, 2};

  points[5] = {1, 1};
  points[6] = {0, 1};
  computeHull();
  for (int i = 0; i < H; i++) {
    printf("%lld %lld\n", hull[i].first, hull[i].second);
  }
  return 0;
  */

  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int n;
    scanf("%d", &n);
    vector<Point> P(n);
    for (int i = 0; i < n; i++) {
      scanf("%lld %lld", &P[i].st, &P[i].nd);
    }

    map<Point, int> res;
    for (auto& p: P) {
      res[p] = n;
    }

    for (int pset = 1; pset <= (1 << n) - 1; pset++) {
      N = 0;
      for (int i = 0; i < n; i++) {
        if (pset & (1 << i)) {
          points[N++] = P[i];
        }
      }
      computeHull();
      for (int i = 0; i < H; i++) {
        int& r = res[hull[i]];
        r = min(r, n - N);
      }
    }
    
    printf("Case #%d:\n", t);
    for (int i = 0; i < n; i++) {
      printf("%d\n", res[P[i]]);
    }
  }
  return 0;
}
