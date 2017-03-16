#include <bits/stdc++.h>
using namespace std;

struct Point {
	long long _x, _y;
	explicit Point(int x = 0, int y = 0): _x(x), _y(y) {}
	Point operator - (const Point& rh) const {
		return Point(_x - rh._x, _y - rh._y);
	}
	long long operator * (const Point& rh) const {
		return _x * rh._y - _y * rh._x;
	}
	bool operator < (const Point& rh) const {
		return _y != rh._y ? _y < rh._y : _x < rh._x;
	}
	bool operator == (const Point& rh) const {
	  return _x == rh._x && _y == rh._y;
  }
} cord[16], points[16];

long long squareDistance(const Point& p1, const Point& p2) {
	return (p1._x - p2._x) * (p1._x - p2._x) + (p1._y - p2._y) * (p1._y - p2._y);
}

bool counterClockWise(const Point& p1, const Point& p2) {
	// p2 在 p1 的逆时针方向 <=> res > 0
	long long res = (p1 - points[0]) * (p2 - points[0]);
	if (res != 0)
		return res > 0;
	else
		// 距离越远的点越在前面
		return squareDistance(p1, points[0]) > squareDistance(p2, points[0]);
}

bool sameDirection(const Point& p1, const Point& p2) {
	return (p1 - points[0]) * (p2 - points[0]) == 0;
}

void calc_convex(int& n) {
  if (n <= 2) return;
	int index = 0, i;
	for (i = 0; i < n; ++i)
		if (points[i] < points[index])
			index = i;
	swap(points[0], points[index]);
	sort(points + 1, points + n, counterClockWise);
	n = unique(points + 1, points + n, sameDirection) - points;
	int top = 1;
	for (i = 2; i < n; ++i) {
		while (top > 0 && (points[top] - points[top - 1]) * (points[i] - points[top - 1]) < 0)
			--top;
		points[++top] = points[i];
	}
	n = top + 1;
}

inline bool on_segment(Point p1, Point p2, Point p3) {
  long long x1 = min(p1._x, p2._x),
      x2 = max(p1._x, p2._x),
      y1 = min(p1._y, p2._y),
      y2 = max(p1._y, p2._y);
  return (p3 - p1) * (p3 - p2) == 0 && x1 <= p3._x && p3._x <= x2
    && y1 <= p3._y && p3._y <= y2;
}

int cov[1 << 15], bits[1 << 15];

int main() {
  for (int i = 1; i < (1 << 15); ++i)
    bits[i] = bits[i >> 1] + (i & 1);
  int test; scanf("%d", &test);
  for (int cas = 1; cas <= test; ++cas) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int x, y; scanf("%d%d", &x, &y);
      cord[i] = Point(x, y);
    }
    for (int s = 0; s < (1 << n); ++s) {
      int cc = 0;
      for (int i = 0; i < n; ++i)
        if (s & (1 << i))
          points[cc++] = cord[i];
      calc_convex(cc);
      cov[s] = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < cc; ++j)
          if (on_segment(points[j], points[(j + 1) % cc], cord[i])) {
            cov[s] |= 1 << i;
            break;
          }
      }
    }
    printf("Case #%d:\n", cas);
    for (int i = 0; i < n; ++i) {
      int ans = n;
      for (int s = 0; s < (1 << n); ++s)
        if (cov[s] & (1 << i))
          ans = min(ans, n - bits[s]);
      printf("%d\n", ans);
    }
  }
  return 0;
}
