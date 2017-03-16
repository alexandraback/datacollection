#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int m[11111];

LL calc(LL x, int b) {
  LL r = 0;
  for (int i = 0; i < b; ++i) {
    r += x / m[i] + (x % m[i] > 0);
  }
  return r;
}

int main() {
  int test; scanf("%d", &test);
  for (int cas = 1; cas <= test; ++cas) {
    int b, n; scanf("%d%d", &b, &n);
    for (int i = 0; i < b; ++i)
      scanf("%d", m + i);
    LL l = 0, r = n * (LL)*max_element(m, m + b) + 1;
    while (l + 1 != r) {
      LL mid = (l + r) / 2;
      if (calc(mid, b) >= n)
        r = mid;
      else
        l = mid;
    }
    int ans = 0;
    LL k = n - calc(l, b);
    for (int i = 0; i < b; ++i)
      if (l % m[i] == 0 && --k == 0) {
        ans = i + 1;
        break;
      }
    printf("Case #%d: %d\n", cas, ans);
  }
  return 0;
}
