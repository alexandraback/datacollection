#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <cmath>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

struct pt {
  ll x, y;
};

bool cmp (pt a, pt b) {
  return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
  if (a.size() == 1)  return;
  sort (a.begin(), a.end(), &cmp);
  pt p1 = a[0],  p2 = a.back();
  vector<pt> up, down;
  up.push_back (p1);
  down.push_back (p1);
  for (size_t i=1; i<a.size(); ++i) {
    if (i==a.size()-1 || cw (p1, a[i], p2)) {
      while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
        up.pop_back();
      up.push_back (a[i]);
    }
    if (i==a.size()-1 || ccw (p1, a[i], p2)) {
      while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
        down.pop_back();
      down.push_back (a[i]);
    }
  }
  a.clear();
  for (size_t i=0; i<up.size(); ++i)
    a.push_back (up[i]);
  for (size_t i=down.size()-2; i>0; --i)
    a.push_back (down[i]);
}

vector<pt> hulls[1 << 15];

int main()
{
  std::ios::sync_with_stdio(false);
  freopen("C-small-attempt1.in", "r", stdin);
  freopen("C_result.txt", "w", stdout);
  //freopen("in.txt", "r", stdin);
  //freopen("result.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  //T = 1;
  for (int i = 0; i < T; ++i)
  {
    vector<pt> pts;
    int n;
    scanf("%d", &n);
    //n = 15;
    for (int i = 0; i < n; ++i)
    {
      pt x;
      scanf("%lld%lld", &x.x, &x.y);
      //x.x = rand();
      //x.y = rand();
      pts.push_back(x);
    }

    printf("Case #%d:", i + 1);
    printf("\n");

    for (int m = 1; m < (1 << n); ++m)
    {
      hulls[m].clear();
      for (int i = 0; i < n; ++i)
      {
        if ((1 << i) & m)
          hulls[m].push_back(pts[i]);
      }
      convex_hull(hulls[m]);
      hulls[m].push_back(hulls[m].front());

    }

    for (int i = 0; i < n; ++i)
    {
      int best = n - 1;

      for (int m = 1; m < (1 << n); ++m)
      {
        if (!((1 << i) & m))
          continue;
      
        int cnt = 0;
        for (int j = 0; j < n; ++j)
        {
          if ((1 << j) & m)
            cnt++;
        }
        bool ok = false;

        for (int j = 0 ; j < int(hulls[m].size()) - 1 && !ok; ++j)
        {
          pt & x = hulls[m][j];
          pt & b = hulls[m][j + 1];
          if (x.x == pts[i].x && x.y == pts[i].y)
            ok = true;

          if ((pts[i].x - x.x) * (b.y - x.y) == (b.x - x.x) * (pts[i].y - x.y))
            ok = true;

        }
        if (ok)
          best = std::min(best, n - cnt);

      }

      printf("%d\n", best);
    }
  }

  fclose(stdin);
  fclose(stdout);

  return 0;
}