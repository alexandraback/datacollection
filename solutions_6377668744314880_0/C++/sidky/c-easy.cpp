#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define rab(i,a,b) for((i)=(a);(i)<=(b);(i)++)
#define Fi(n) rep(i,n)
#define Fj(n) rep(j,n)
#define Fk(n) rep(k,n)
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()

struct POINT {
  long X;
  long Y;
  int idx;
};

int cross(const POINT &p1, const POINT &p2) {
  long c =  p1.X * p2.Y - p2.X * p1.Y;

  if(c == 0) {
    return (p1.X * p1.X + p1.Y * p2.Y) <= (p2.X * p2.X + p2.Y * p2.Y);
  } else if (c < 0) return -1;
  else return 1;
}

POINT pivot;

bool compare(const POINT &p1, const POINT &p2) {
  return cross(p1,p2) >= 0;
}

bool left(const POINT &p0, const POINT &p1, const POINT &p2) {
  POINT r1,r2;

  r1.X = (p1.X - p0.X);
  r1.Y = (p1.Y - p0.Y);

  r2.X = (p2.X - p0.X);
  r2.Y = (p2.Y - p0.Y);

  return compare(r1, r2);
}

vector<POINT> convex(const vector<POINT>& pts) {
  vector <POINT> p = pts;
  vector <POINT> convex;
  int i;

  for(i = 1; i < sz(p); i++) {
    if(p[i].Y < p[0].Y || (p[i].Y == p[0].Y && p[i].X < p[0].X)) {
      swap(p[i], p[0]);
    }
  }

  for(i = 0; i < sz(p); i++) {
    p[i].X -= p[0].X;
    p[i].Y -= p[0].Y;
  }

  sort(p.begin() + 1, p.end(), compare);

  convex.push_back(p[0]);
  convex.push_back(p[1]);
  convex.push_back(p[2]);

  for(i = 3; i < sz(p); i++) {
    while(true) {
      int m = sz(convex);
      //printf("size = %d\n",m);
      if (left(convex[m-2], convex[m-1], p[i])) break;
      convex.pop_back();
    }
    convex.push_back(p[i]);
  }

  return convex;
}

bool linear(const vector<POINT> &p) {
  int i,j,k;

  Fi(sz(p)) Fj(sz(p)) Fk(sz(p)) {
    POINT r1, r2;

    r1.X = p[j].X - p[i].X;
    r1.Y = p[j].Y - p[i].Y;
    r2.X = p[k].X - p[i].X;
    r2.Y = p[k].Y - p[i].Y;

    if(cross(r1,r2) != 0) return false;
  }
  return true;
}


int main() {
  int T, cs;

  vector <POINT> p;
  vector <int> min_remove;
  POINT x;
  int i,N,j,k;

  scanf("%d", &T);

  rab(cs,1,T) {
    scanf("%d",&N);

    p.clear();
    Fi(N) {
      scanf("%ld %ld", &x.X, &x.Y);
      x.idx = i;
      p.push_back(x);
    }

    min_remove.clear();
    if (N > 3) {
      Fi(N) min_remove.push_back(N - 3);

      Fi(1 << N) {
        vector <POINT> subset;

        Fj(N) {
          if(i & (1 << j)) {
            subset.push_back(p[j]);
          }
        }

        if(sz(subset) > 3 && !linear(subset)) {
          vector <POINT> c = convex(subset);

          Fk(N) {
            Fj(sz(c)) {
              int l = sz(c);
              POINT r1, r2;

              r1.X = p[k].X - c[j].X;
              r1.Y = p[k].Y - c[j].Y;
              r2.X = c[(j+1)%l].X - c[j].X;
              r2.Y = c[(j+1)%l].Y - c[j].Y;

              if(cross(r1, r2) == 0) {
                min_remove[k] = min(min_remove[k], (int)(N - sz(subset)));
                //if(min_remove[k] == (N - (sz(subset)))) {
                //printf("%d: %d -> %d\n", k, i, min_remove[k]);
                // for(int l = 0; l < sz(c); l++) printf("%d (%ld, %ld) ->", c[l].idx, c[l].X, c[l].Y);
                // printf("\n");
                // }
              }
            }
          }
        } else {
          Fj(N) {
            if(i & (1 << j)) min_remove[j] = min(min_remove[j], (int)(N - sz(subset)));
          }
        }
      }
    } else {
      Fi(N) min_remove.push_back(0);
    }

    printf("Case #%d:\n",cs);

    Fi(N) {
      printf("%d\n",min_remove[i]);
    }
  }

  return 0;
}
