
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
  int x, y;
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

bool cmp(const point_t p1, const point_t p2) {
  return p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y;
}

int graham(point_t *p, int n, int *sk) {
  int top = 0;
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
  return top;
}

bool insideConvex(point_t *convex, int n, point_t t) { // O(logN), convex polygen
  if (n == 2) return onSeg(t, convex[1], convex[2]);
  int l = 2, r = n;
  while (l < r) {
    int mid = (l + r) / 2 + 1;
    int side = sgncmp(cross(convex[mid] - convex[1], t - convex[1]));
    if (side == 1) l = mid;
    else r = mid - 1;
  }
  int s = sgncmp(cross(convex[l] - convex[1], t - convex[1]));
  if (s == -1 || l == n) return false;
  point_t v = convex[l + 1] - convex[l];
  if (sgncmp(cross(v, t - convex[l])) >= 0) return true;
  return false;
}

int answer[maxN];

void check(int submask) {
  static point_t p2[maxN], p3[maxN];
  static int sk[maxN];
  int cnt = 0;
  for (int i = 1, m = submask; i <= n; ++i) {
    if (m & 1) {
      p2[++cnt] = p[i];
    }
    m >>= 1;
  }
  int cnt2 = graham(p2, cnt, sk), ret = 0;
  for (int i = 1; i <= cnt2; ++i) {
    p3[i] = p2[sk[i]];
  }
  for (int i = 1; i <= n; ++i) {
    if (insideConvex(p3, cnt2, p[i])) ++ret;
  }
  for (int i = 1; i <= n; ++i) {
    if ((submask >> (i - 1)) & 1) {
      bool on = false;
      for (int j = 1; j <= cnt2; ++j) {
        if (onSeg(p[i], p2[sk[j]], p2[sk[j + 1]])) {
          on = true;
          break;
        }
      }
      if (on) {
        answer[i] = min(answer[i], n - ret);
      }
    }
  }
}

int main() {
  freopen("C-small-attempt1.in", "r", stdin);
  freopen("C-small-attempt1.out", "w", stdout);
  read(tests);
  for (int tt = 1; tt <= tests; ++tt) {
    read(n);
    for (int i = 1; i <= n; ++i) {
      p[i].read();
    }
    for (int i = 1; i <= n; ++i) answer[i] = n - 1;
    for (int sub = 1; sub < (1 << n); ++sub) {
      check(sub);
    }
    printf("Case #%d:\n", tt);
    for (int i = 1; i <= n; ++i) {
      printf("%d\n", answer[i]);
    }
  }
  return 0;
}
