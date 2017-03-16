#include <bits/stdc++.h>
using namespace std;
long long x[10005], y[10005];
int n, q, ans[10005];
int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &x[i], &y[i]);
  }
  memset(ans, 0x20, sizeof ans);
  if (n <= 2) {
    ans[0] = 0;
    ans[1] = 0;
  }
  for (int i = 0; i < n; i++) {
  	for (int j = 0; j < n; j++) {
      if (i == j) continue;
      int neg = 0, pos = 0;
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        long long t = (x[i] * y[k]) - (x[j] * y[k]) + x[j] * y[i] - x[k] * y[i] + x[k] * y[j] - x[i] * y[j];
        if (t < 0) {
          neg++;
        }
        if (t > 0) {
          pos++;
        }
  	  }
  	  ans[i] = min(ans[i], min(neg, pos));
  	  ans[j] = min(ans[j], min(neg, pos));
  	}
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n", ans[i]);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  for (int caseno = 1; caseno <= t; caseno++) {
    printf("Case #%d:\n", caseno);
    solve();
  }
  return 0;
}

