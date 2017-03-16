#include <stdio.h>
#include <algorithm>
using namespace std;

int mushes[1002];

int main() {
  int t, n, m = 0;
  scanf("%d", &t);
  for (int c = 1; c <= t; ++c) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &mushes[i]);
      m = max(m, mushes[i]);
    }
    
    int ans1 = 0, prev = mushes[0];
    for (int i = 1; i < n; ++i) {
      if (prev - mushes[i] > 0)
        ans1 += prev - mushes[i];
      prev = mushes[i];
    }
    
    int ans2 = (1 << 30);
    for (int r = 0; r <= m; ++r) {
      int this_ans = 0;
      bool possible = true;
      for (int i = 1; i < n && possible; ++i) {
        int left = mushes[i - 1] - r; if (left < 0) left = 0;
        if (left > mushes[i]) possible = false;
        this_ans += mushes[i - 1] - left;
      }
      if (possible)
        ans2 = min(ans2, this_ans);
    }
    
    printf("Case #%d: %d %d\n", c, ans1, ans2);
  }
  return 0;
}