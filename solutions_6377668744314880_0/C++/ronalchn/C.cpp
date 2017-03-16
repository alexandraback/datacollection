#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
struct point{
  int x,y,i;
  point(int x,int y,int i) : x(x), y(y), i(i) {}
  point() {}
  bool operator<(const point &p) const {
    return make_pair(x,y) < make_pair(p.x,p.y);
  }
};

long long ccw(point p1, point p2, point p3) {
  return (p2.x-p1.x)*(long long)(p3.y-p1.y) - (p2.y-p1.y)*(long long)(p3.x-p1.x);
}

vector<point> points;
vector<int> p2(20);

vector<point> convh(vector<point> &points, int bitmask) {
  vector<point> U, L;
  for (int i=0;i<points.size();i++) {
    if (!(bitmask & p2[i])) continue;
    while (L.size()>=2 && ccw(L[L.size()-2],L[L.size()-1],points[i])<0)
      L.pop_back();
    L.push_back(points[i]);
    //for (int j=0;j<L.size();j++) printf("(%d) %d %d, ",L[j].i,L[j].x,L[j].y);
    //printf("\n");
  }
  for (int i=points.size()-1;i>=0;i--) {
    if (!(bitmask & p2[i])) continue;
    while (U.size()>=2 && ccw(U[U.size()-2],U[U.size()-1],points[i])<0)
      U.pop_back();
    U.push_back(points[i]);
  }
  if (U.size()>=2) L.insert(L.end(),U.begin()+1,U.end()-1);
  return L;
}

int main() {
  int T;

  cin >> T;
  p2[0]=1;
  for (int i=1;i<20;i++) p2[i]=p2[i-1]*2;

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
    sort(points.begin(),points.end());
    //if (t<3) continue;

    vector<int> ans(N,N);
    for (int i=0;i<p2[N];i++) {
      //i = 2047;
      int count = __builtin_popcount(i);
      // try convh it
      vector<point> ps = convh(points,i);
      for (int j=0;j<ps.size();j++) {
        ans[ps[j].i] = min(ans[ps[j].i],N-count);
      }
      //break;
    }
    printf("Case #%d:\n",t);
    for (int i=0;i<N;i++) {
      printf("%d\n",ans[i]);
    }
  }

}


