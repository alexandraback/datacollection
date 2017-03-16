// C++11
#include <cstdio>
#include <algorithm>
using namespace std;

struct point {
  int ev, a, x, y;
  void set(int setev, int aoff, int xx, int yy) {
    if(xx > 0 && yy >= 0) {
      a = 0;
      x = xx;
      y = yy;
    } else if(yy > 0 && -xx >= 0) {
      a = 1;
      x = yy;
      y = -xx;
    } else if(-xx > 0 && -yy >= 0) {
      a = 2;
      x = -xx;
      y = -yy;
    } else {
      a = 3;
      x = -yy;
      y = xx;
    }
    ev = setev;
    a += aoff;
  }
  bool operator<(const point& pt) const {
    if(a != pt.a) return a < pt.a;
    long long r1 = (long long)y*pt.x;
    long long r2 = (long long)pt.y*x;
    if(r1 != r2) return r1 < r2;
    return ev > pt.ev;
  }
};

int main() {
  int T; scanf("%d", &T);
  for(int tci = 0; tci < T; ++tci) {
    int N; scanf("%d", &N);
    static int xs[3000], ys[3000];
    for(int i = 0; i < N; ++i) {
      scanf("%d%d", &xs[i], &ys[i]);
    }
    printf("Case #%d:\n", tci+1);
    static point pts[12000];
    for(int i = 0; i < N; ++i) {
      int pts_size = 0;
      for(int j = 0; j < N; ++j) {
        if(i == j) continue;
        pts[pts_size++].set(1, 0, xs[j]-xs[i], ys[j]-ys[i]);
        pts[pts_size++].set(-1, 2, xs[j]-xs[i], ys[j]-ys[i]);
        pts[pts_size++].set(1, 4, xs[j]-xs[i], ys[j]-ys[i]);
        pts[pts_size++].set(-1, 6, xs[j]-xs[i], ys[j]-ys[i]);
      }
      sort(pts, pts+pts_size);
      int maxsum = 0;
      int sum = 0;
      for(int j = 0; ; ++j) {
        maxsum = max(maxsum, sum);
        if(j >= pts_size) break;
        // fprintf(stderr, "i=%d, j=%d: (%d, %d, %d, %d)\n",
        //     i, j, pts[j].ev, pts[j].a, pts[j].x, pts[j].y);
        sum += pts[j].ev;
      }
      printf("%d\n", N-1-maxsum);
    }
  }
  return 0;
}
