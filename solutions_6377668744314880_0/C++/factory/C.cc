#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef int64_t i64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> ii;

struct point
{
  i64 x,y;
  int num;
  bool operator()(const point &a,const point &b) {
    if(a.x<b.x) return true;
    if(a.x>b.x) return false;
    if(a.y<b.y) return true;
    if(a.y>b.y) return false;
    if(a.num<b.num) return true;
    return false;
  }
};
typedef vector<point> vp;
inline i64 ccw(point a,point b,point c) {
  i64 sum=0;
  sum+=(a.x*b.y+b.x*c.y+c.x*a.y);
  sum-=(a.y*b.x+b.y*c.x+c.y*a.x);
  return sum;
}

bool PointIsOnTheBoundary(vp& p, int num) {
  sort(p.begin(), p.end(), point());

  vp bound(p.size() * 2);

  int x = 0;
  for (const auto& po : p) {
    while (x >= 2 && ccw(bound[x - 2], bound[x - 1], po) < 0LL) {
      --x;
    }
    bound[x++] = po;
  }
  int y = x + 1;
  for (int i = p.size() - 2; i >= 0; --i) {
    while (x >= y && ccw(bound[x - 2], bound[x - 1], p[i]) < 0LL) {
      --x;
    }
    bound[x++] = p[i];
  }
  bound.resize(x);
  for (const auto& ppp : bound) {
    if (ppp.num == num) {
      return true;
    }
  }
  return false;
}

int IntPow(int x, int p) {
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = IntPow(x, p / 2);
  if (p % 2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}


int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  int T = 0;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    int N = 0;
    cin >> N;
    vp points(N);
    for (int i = 0; i < N; ++i) {
      int x = 0;
      int y = 0;
      cin >> x >> y;
      points[i].x = x;
      points[i].y = y;
      points[i].num = i;
    }

    cout << "Case #" << tt << ":\n";

    for (const auto& p : points) {
      if (N <= 3) {
        cout << "0\n";
        continue;
      }
      int max_try = N - 3;
      int answer = max_try;
      int max_bitmask = IntPow(2, N);
      for (int i = 0; i < max_bitmask; ++i) {
        unordered_set<int> p_exclude;
        bool tryy = true;
        for (int j = 0; j < N; ++j) {
          if (((1 << j) & i) != 0) {
            if (j == p.num) {
              tryy = false;
              break;
            }
            p_exclude.insert(j);
          }
        }
        if (p_exclude.size() > max_try) {
          tryy = false;
        }
        if (!tryy) {
          continue;
        }

        vp copyd(points);
        for (auto it = copyd.begin(); it != copyd.end();) {
          if (p_exclude.find(it->num) != p_exclude.end()) {
            it = copyd.erase(it);
          } else {
            ++it;
          }
        }

        if (PointIsOnTheBoundary(copyd, p.num)) {
          answer = min(answer, static_cast<int>(p_exclude.size()));
        }
      }
      cout << answer << "\n";
    }
  }
  
  return 0;
}
