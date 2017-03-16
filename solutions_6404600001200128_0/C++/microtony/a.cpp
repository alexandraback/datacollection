#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main() {
  int t;
  scanf("%d", &t);
  for (int caseno = 1; caseno <= t; caseno++) {
    int n, m = 0, sum = 0, sum2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] < a[i]) {
        sum += a[i] - a[i + 1];
        m = max(m, a[i] - a[i + 1]);
      }
    }
    int last = a[0];
    for (int i = 1; i < n; i++) {
      int target = max(0, last - m);
      sum2 += last - target;
      last = a[i];
    }
    printf("Case #%d: %d %d\n", caseno, sum, sum2);
  }
  return 0;
}

