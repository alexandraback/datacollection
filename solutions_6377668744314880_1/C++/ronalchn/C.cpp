#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int xx, yy;

struct point;

struct point{
  int x,y,i;
  point(int x,int y,int i) : x(x), y(y), i(i) {}
  point() {}
  bool operator<(const point &p) const {
    if (y==yy && x==xx) return false;
    if (p.y==yy && p.x==xx) return true;
    return atan2((double)y-yy,(double)x-xx) < atan2((double)p.y-yy,(double)p.x-xx);
    //return ccw()
    //return make_pair(x,y) < make_pair(p.x,p.y);
  }
};

long long ccw(point p1, point p2, point p3) {
  return (p2.x-p1.x)*(long long)(p3.y-p1.y) - (p2.y-p1.y)*(long long)(p3.x-p1.x);
}

vector<point> points;
vector<int> p2(20);

int main() {
  int T;

  cin >> T;
  p2[0]=1;
  for (int i=1;i<20;i++) p2[i]=p2[i-1]*2;
  vector<point> ps;

  for (int t=1;t<=T;t++) {
    int N;
    cin >> N;
    points.clear();

    for (int i=0;i<N;i++) {
      point p;
      p.i = i;
      cin >> p.x >> p.y;
      points.push_back(p);
    }
    ps = points;
    //sort(points.begin(),points.end());
    printf("Case #%d:\n",t);
    for (int i=0;i<N;i++) {
      xx = points[i].x;
      yy = points[i].y;
      sort(ps.begin(),ps.end());
      //printf("%d\n",ans[i]);

      int k=0;
      int best = N-1;
      //printf("start\n");
      for (int j=0;j<N-1;j++) {
        if (j==k) {
          k++;
          if (k==N-1) k=0;
        }
        while (ccw(ps[j],points[i],ps[k])<0) {
          k++;
          if (k==N-1) k=0;
        }
        //printf("j=%d (%d,%d) to k=%d (%d,%d)\n",j,ps[j].x,ps[j].y,k,ps[k].x,ps[k].y);
        best = min(best,((k-j-1)+(N-1))%(N-1));
      }
      printf("%d\n", best);
    }
    //return 0;
  }

}


