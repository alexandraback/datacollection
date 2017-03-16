#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct point {
  long long x, y;
};

int n;
point p[6008];
long double a[6011];

long long crp(point o, point a, point b) {
  return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

const long double PI = 3.141592653589793;
const long double eps = 1e-12;

int main() {
  int t, T;
  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%lld %lld", &p[i].x, &p[i].y);
    }

    printf("Case #%d:\n", t);
    for (int i = 0; i < n; ++i) {
      if (n == 1) {
        printf("0\n");
        continue;
      }
      int ans = n + 10;
      int k = 0;
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        a[k++] = atan2((long double) p[j].y - p[i].y, (long double) p[j].x - p[i].x);
        a[k++] = atan2((long double) p[j].y - p[i].y, (long double) p[j].x - p[i].x) + PI * 2.0;
      }
      sort(a, a + k);
      int r = 0;
      for (int j = 0; j < k / 2; ++j) {
        while (a[j] + PI > a[r] + eps) {
          ++r;
        }
        ans = min(ans, r - j - 1);
        ans = min(ans, n - 2 - (r - j - 1));
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
