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

bool CmpPoint(const Point &a, const Point &b) {
  return atan2(a.y, a.x) < atan2(b.y, b.x);
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
    std::sort(poi.begin(), poi.end(), CmpPoint);
    int ans = n - 1;
    for (size_t i = 0, j = 0; i < poi.size(); ++i) {
      size_t cnt = 0;
      while (Det(poi[i], poi[j]) >= 0) {
        j = (j + 1) % poi.size();
        if (++cnt == poi.size()) {
          ans = 0;
          break;
        }
      }
      if (!ans) break;
      if (i < j) {
        ans = std::min(ans, int(j - i));
        ans = std::min(ans, int(poi.size() - j + i));
      } else {
        ans = std::min(ans, int(i - j));
        ans = std::min(ans, int(poi.size() - i + j));
      }
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
