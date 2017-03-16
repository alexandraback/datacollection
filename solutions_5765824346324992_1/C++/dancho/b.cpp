#include <cstdio>
#include <cstring>

int n, b;
int m[1024];

int main() {
  int t, T;
  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    scanf("%d %d", &b, &n);
    for (int i = 0; i < b; ++i) {
      scanf("%d", &m[i]);
    }

    long long l = -1, r = (1LL << 61);
    while (l + 1 < r) {
      long long mi = (l + r) / 2;
      long long cnt = 0;
      for (int i = 0; i < b; ++i) {
        cnt += (mi / m[i] + 1);
        if (cnt >= n) {
          break;
        }
      }
      if (cnt >= n) {
        r = mi;
      } else {
        l = mi;
      }
    }

    int ret = -1;
    long long pr = 0;
    if (r >= 1) {
      for (int i = 0; i < b; ++i) {
        pr += ((r - 1) / m[i] + 1);
      }
    }

    for (int i = 0; i < b; ++i) {
      if (r % m[i] == 0) {
        ++pr;
        if (pr == n) {
          ret = i + 1;
          break;
        }
      }
    }
    printf("Case #%d: %d\n", t, ret);
  }
  return 0;
}
