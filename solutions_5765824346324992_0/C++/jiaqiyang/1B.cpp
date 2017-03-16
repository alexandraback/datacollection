#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long i64;

const int N = 1000 + 10;

int tcase, m, n;
int a[N];

i64 count(i64 x) {
  i64 res = 0;
  for (i64 i = 1; i <= m; ++i) res += (x / a[i]) + 1;
  return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &tcase);
  for (int tid = 1; tid <= tcase; ++tid) {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i) scanf("%d", a + i);
    i64 l = 0, r = 1LL << 50;
    while (l < r) {
      i64 mid = (l + r + 1) / 2;
      if (count(mid) >= n - 1) r = mid - 1; else l = mid;
    }
    static int t[N];
    for (int i = 1; i <= m; ++i) t[i] = a[i];
    if (count(l) < n - 1) {
      n -= count(l);
      for (int i = 1; i <= m; ++i) t[i] -= l % t[i];
    }
    int ans = 0;
    while (!ans && n) {
      int det = *std::min_element(t + 1, t + m + 1);
      for (int i = 1; i <= m; ++i) {
        if ((t[i] -= det) == 0) {
          t[i] = a[i];
          if (--n == 0) {
            ans = i;
            break;
          }
        }
      }
    }
    printf("Case #%d: %d\n", tid, ans);
  }
  return 0;
}
