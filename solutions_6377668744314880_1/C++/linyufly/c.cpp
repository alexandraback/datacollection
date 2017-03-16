#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long Int64;

const int maxn = 100000;

struct Point {
  int x_, y_;

  Point() {
  }

  Point(int x, int y) : x_(x), y_(y) {
  }
};

int x[maxn], y[maxn];
Point points[maxn];
int n, s_n;

int category(int x, int y) {
  if (x > 0 && y == 0) {
    return 0;
  }

  if (x > 0 && y > 0) {
    return 1;
  }

  if (x == 0 && y > 0) {
    return 2;
  }

  if (x < 0 && y > 0) {
    return 3;
  }

  if (x < 0 && y == 0) {
    return 4;
  }

  if (x < 0 && y < 0) {
    return 5;
  }

  if (x == 0 && y < 0) {
    return 6;
  }

  if (x > 0 && y < 0) {
    return 7;
  }
}

bool angle_comparison(const Point &p_1, const Point &p_2) {
  int c_1 = category(p_1.x_, p_1.y_);
  int c_2 = category(p_2.x_, p_2.y_);

  if (c_1 != c_2) {
    return c_1 < c_2;
  }

  return static_cast<Int64>(p_1.x_) * p_2.y_ - static_cast<Int64>(p_1.y_) * p_2.x_ > 0;
}

void solve() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }

  for (int i = 0; i < n; i++) {
    s_n = 0;

    for (int j = 0; j < n; j++) {
      if (j != i) {
        points[s_n].x_ = x[j] - x[i];
        points[s_n].y_ = y[j] - y[i];

        if (points[s_n].x_ == 0 && points[s_n].y_ == 0) {
          continue;
        }

        s_n++;
      }
    }

    if (s_n == 0) {
      printf("0\n");
      continue;
    }

    sort(points, points + s_n, angle_comparison);

    int count = 0;
    int ans = s_n;

    for (int start = 0; start < s_n; start++) {
      for (; count < s_n; count++) {
        int curr = (start + count) % s_n;

        if (static_cast<Int64>(points[start].x_) * points[curr].y_ - static_cast<Int64>(points[start].y_) * points[curr].x_ < 0) {
          break;
        }
      }

      if (s_n - count < ans) {
        ans = s_n - count;
      }

      if (count > 0) {
        count--;
      }
    }

    printf("%d\n", ans);
  }
}

int main() {
  int tt;
  scanf("%d", &tt);

  for (int t = 1; t <= tt; t++) {
    printf("Case #%d:\n", t);

    solve();
  }

  return 0;
}

