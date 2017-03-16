#include <algorithm>
#include <cstdio>
#include <cstring>

long long sgn(long long x) {
  return x < 0 ? -1 : x > 0;
}

struct Point {
  long long x, y;
};

const int N = 20;

Point points[N];

long long det(long long x1, long long y1, long long x2, long long y2) {
  return x1 * y2 - x2 * y1;
}

long long Cross(Point a, Point b, Point s) {
  long long x1 = a.x - s.x, y1 = a.y - s.y;
  long long x2 = b.x - s.x, y2 = b.y - s.y;
  return det(x1, y1, x2, y2);
}

long long sqr(long long x) {
  return x * x;
}

long long Dist(Point a, Point b) {
  return sqr(a.x - b.x) + sqr(a.y - b.y);
}

int Compare(Point a, Point b) {
  if (sgn(Cross(a, b, points[0])) == 1
      || (sgn(Cross(a, b, points[0])) == 0
          && Dist(points[0], a) < Dist(points[0], b))) {
    return true;
  }
  return false;
}

Point stack[N];

long long Scan(int n) {
  if (n <= 1) {
    return n;
  }
  int now = 0;
  for (int i = 1; i < n; ++ i) {
    if (sgn(points[i].y - points[now].y) == 1
        || (sgn(points[i].y - points[now].y) == 0
            && sgn(points[i].x - points[now].x) == -1)) {
      now = i;
    }
  }
  std::swap(points[0], points[now]);
  std::sort(points + 1, points + n, Compare);
  int top = 2;
  for (int i = 0; i < 2; ++ i) {
    stack[i] = points[i];
  }
  for (int i = 2; i < n; ++ i) {
    while (top > 1 && sgn(
        Cross(stack[top - 1], points[i], stack[top - 2])) <= 0) {
      top --;
    }
    stack[top ++] = points[i];
  }
  return top;
}

bool OnSegment(Point a, Point b, Point k) {
  return det(k.x - a.x, k.y - a.y, b.x - a.x, b.y - a.y) == 0
      && k.x >= std::min(a.x, b.x) && k.x <= std::max(a.x, b.x)
      && k.y >= std::min(a.y, b.y) && k.y <= std::max(a.y, b.y);
}

const int INF = 1000;

Point input[N];
int result[N];

int main() {
  int test;
  scanf("%d", &test);
  for (int t = 1; t <= test; ++ t) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
      scanf("%lld %lld", &input[i].x, &input[i].y);
      result[i] = INF;
    }

    printf("Case #%d:\n", t);
    if (n == 1) {
      puts("0");
      continue;
    }

    for (int mask = 0; mask < 1 << n; ++ mask) {
      int now = 0;
      for (int i = 1; i <= n; ++ i) {
        if (mask & (1 << (i - 1))) {
          points[now ++] = input[i];
        }
      }
      int m = Scan(now);
      for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j < m; ++ j) {
          if (OnSegment(stack[j - 1], stack[j], input[i])) {
            result[i] = std::min(result[i], n - now);
          }
        }
        if (OnSegment(stack[0], stack[m - 1], input[i])) {
          result[i] = std::min(result[i], n - now);
        }
      }
    }
    for (int i = 1; i <= n; ++ i) {
      printf("%d\n", result[i]);
    }
  }
  return 0;
}
