#include <cmath>
#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
using std::vector;

const int MAXN = 3333;

struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}

  void Input() {
    assert(scanf("%d%d", &x, &y) == 2);
  }
} p[MAXN];

int n;

void Init() {
  assert(scanf("%d", &n) == 1);
  for (int i = 0; i < n; ++i) {
    p[i].Input();
  }
}

long long Det(const Point &a, const Point &b) {
  return (long long)a.x * b.y - (long long)b.x * a.y;
}

void Work() {
  for (int i = 0; i < n; ++i) {
    vector<Point> poi;
    for (int j = 0; j < n; ++j)
      if (i != j)
        poi.push_back(Point(p[j].x - p[i].x, p[j].y - p[i].y));
    int ans = n - 1;
    for (const auto &p1 : poi) {
      int cnt1 = 0;
      int cnt2 = 0;
      for (const auto &p2 : poi) {
        if (Det(p1, p2) < 0)
          ++cnt1;
        if (Det(p1, p2) > 0)
          ++cnt2;
      }
      if (cnt1 < ans)
        ans = cnt1;
      if (cnt2 < ans)
        ans = cnt2;
    }
    printf("%d\n", ans);
  }
}

int main() {
  int cases;
  assert(scanf("%d", &cases) == 1);
  for (int i = 1; i <= cases; ++i) {
    printf("Case #%d:\n", i);
    Init();
    Work();
  }
  return 0;
}
