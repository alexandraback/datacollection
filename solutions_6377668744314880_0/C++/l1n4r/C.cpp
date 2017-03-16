
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <memory>
using namespace std;

struct point {
  int x;
  int y;
};

bool cmp(const point& a, const point& b) {
  return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

bool eq(const point& a, const point& b) { return (a.x == b.x && a.y == b.y); }

bool collinear(const point& a, const point& b, const point& c) {
  return 1ll * a.x * (b.y - c.y) + 1ll * b.x * (c.y - a.y) +
             1ll * c.x * (a.y - b.y) ==
         0;
}

bool ccw(const point& a, const point& b, const point& c) {
  return 1ll * a.x * (b.y - c.y) + 1ll * b.x * (c.y - a.y) +
             1ll * c.x * (a.y - b.y) >
         0;
}

void convex_hull(vector<point> p, vector<point>& h) {
  sort(p.begin(), p.end(), cmp);
  p.erase(unique(p.begin(), p.end(), eq), p.end());

  vector<point> up, down;
  point head = p[0], tail = p.back();

  up.push_back(head);
  down.push_back(head);

  for (int i = 1; i < (int)p.size(); i++) {
    if (i == (int)p.size() - 1 || !ccw(tail, head, p[i])) {
      while ((int)up.size() >= 2 &&
             (!collinear(up[up.size() - 2], up.back(), p[i]) &&
              ccw(up[up.size() - 2], up.back(), p[i]))) {
        up.pop_back();
      }
      up.push_back(p[i]);
    }
    if (i == (int)p.size() - 1 || ccw(tail, head, p[i]) ||
        collinear(tail, head, p[i])) {
      while ((int)down.size() >= 2 &&
             (!collinear(down[down.size() - 2], down.back(), p[i]) &&
              !ccw(down[down.size() - 2], down.back(), p[i]))) {
        down.pop_back();
      }
      down.push_back(p[i]);
    }
  }

  h.clear();
  for (int i = 0; i < (int)up.size(); i++) {
    h.push_back(up[i]);
  }
  for (int i = (int)down.size() - 2; i > 0; i--) {
    h.push_back(down[i]);
  }
}

int main() {
  int test_cases;
  scanf("%d", &test_cases);

  for (int test_case = 1; test_case <= test_cases; test_case++) {
    int n;
    scanf("%d", &n);
    vector<point> p(n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &p[i].x, &p[i].y);
    }

    vector<int> ans(n, max(n - 3, 0));
    for (int m = 0; m < (1 << n); m++) {
      vector<point> t;
      for (int i = 0; i < n; i++) {
        if (m & (1 << i)) {
          t.push_back(p[i]);
        }
      }

      if (t.size() > 3) {
        const int cut = n - t.size();

        vector<point> h;
        convex_hull(t, h);

        for (int i = 0; i < (int)h.size(); i++) {
          for (int j = 0; j < (int)p.size(); j++) {
            if (h[i].x == p[j].x && h[i].y == p[j].y) {
              ans[j] = min(ans[j], cut);
            }
          }
        }
      }
    }
    printf("Case #%d:\n", test_case);
    for (int i = 0; i < n; i++) {
      printf("%d\n", ans[i]);
    }
  }

  return 0;
}