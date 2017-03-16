
#include <bits/stdc++.h>

typedef long long LL;
const int maxint = 0x7f7f7f7f, mod = 1000000007;
const double eps = 1e-8, pi = acos(-1.0);

void read() { }
template<typename... T> void read(int &h, T &... t) {
  scanf("%d", &h); read(t...);
}
template<typename... T> void read(LL &h, T &... t) {
  scanf("%lld", &h); read(t...);
}
template<typename... T> void read(double &h, T &... t) {
  scanf("%lf", &h); read(t...);
}

#define abs _abs
template<typename T> T abs(const T &h) {
  return h > 0 ? h : -h;
}

using namespace std;

const int maxN = 3333;

struct point_t {
  int x, y, index;
  double angle;
  point_t() { }
  point_t(int tx, int ty) : x(tx), y(ty) { }
  point_t operator-(const point_t &r) const {
    return point_t(x - r.x, y - r.y);
  }
  point_t operator+(const point_t &r) const {
    return point_t(x + r.x, y + r.y);
  }
  point_t operator*(const int r) const {
    return point_t(x * r, y * r);
  }
  point_t operator/(const int r) const {
    return point_t(x / r, y / r);
  }
  point_t rot90() const {
    return point_t(-y, x);
  }
  void read() {
    ::read(x, y);
  }
};

int tests, n;
point_t p[maxN];

int sgncmp(LL x) {
  if (x == 0) {
    return 0;
  } else if (x < 0) return -1;
  return 1;
}

LL cross(point_t p1, point_t p2) {
  return (LL)p1.x * p2.y - (LL)p2.x * p1.y;
}

LL dot(point_t p1, point_t p2) {
  return (LL)p1.x * p2.x + (LL)p1.y * p2.y;
}

LL area(point_t p1, point_t p2, point_t p3) {
  return cross(p2 - p1, p3 - p1);
}

bool coLine(point_t p1, point_t p2, point_t p3) {
  return sgncmp(area(p1, p2, p3)) == 0;
}

bool onSeg(point_t p, point_t a, point_t b) {
  return sgncmp(cross(a - p, b - p)) == 0 && sgncmp(dot(a - p, b - p)) <= 0;
}

bool cmp(const point_t &p1, const point_t &p2) {
  return p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y;
}

bool cmpAngle(const point_t &p1, const point_t &p2) {
  return p1.angle < p2.angle;
}

bool cmpIndex(const point_t &p1, const point_t &p2) {
  return p1.index < p2.index;
}

set<int> graham(point_t *p, int n) {
  int top = 0;
  static int sk[maxN];
  sort(p + 1, p + 1 + n, cmp);
  memset(sk, 0, sizeof(sk));
  top = 2, sk[1] = 1, sk[2] = 2;
  for (int i = 3; i <= n; ++i) {
    while (top >= 2 && sgncmp(cross(p[i] - p[sk[top - 1]], p[sk[top]] - p[sk[top - 1]])) >= 0) --top;
    sk[++top] = i;
  }
  int ttop = top;
  for (int i = n - 1; i >= 1; --i) {
    while (top > ttop && sgncmp(cross(p[i] - p[sk[top - 1]], p[sk[top]] - p[sk[top - 1]])) >= 0) --top;
    sk[++top] = i;
  }
  --top;
  set<int> ret;
  for (int i = 1; i <= top; ++i) {
    ret.insert(p[sk[i]].index);
  }
  sort(p + 1, p + 1 + n, cmpIndex);
  return ret;
}

set<int> onConvex;

int solve(point_t *p2, int k) {
  auto next = [&](int i) -> int {
    i += 1;
    if (i == n) i = 1;
    return i;
  };
  if (n == 1 || n == 2) return 0;
  if (onConvex.count(k)) return 0;
  static point_t p[maxN];
  for (int i = 1, j = 0; i <= n; ++i) {
    if (i == k) continue;
    p[++j] = p2[i] - p2[k];
    p[j].angle = atan2(double(p[j].y), double(p[j].x));
  }
  sort(p + 1, p + n, cmpAngle);
  int pointer = 1, cnt = 2, result = 2;
  for (int i = 1; i < n; i += 1) {
    while (next(pointer) != i) {
      if (sgncmp(cross(p[i], p[next(pointer)])) >= 0) {
        pointer = next(pointer);
        ++cnt;
      } else break;
    }
    result = max(result, cnt);
    cnt -= 1;
  }  
  return n - result;
}

int main() {
  freopen("C-large.in", "r", stdin);
  freopen("C-large.out", "w", stdout);
  read(tests);
  for (int tt = 1; tt <= tests; ++tt) {
    read(n);
    for (int i = 1; i <= n; ++i) {
      p[i].read();
      p[i].index = i;
    }
    onConvex = graham(p, n);
    printf("Case #%d:\n", tt);
    for (int i = 1; i <= n; ++i) {
      printf("%d\n", solve(p, i));
    }
  }
  return 0;
}
