#include <stdio.h>

#include <algorithm>
#include <vector>


int main() {
  int z, zzz;
  scanf("%d", &zzz);
  for (z = 1; z <= zzz; ++z) {
    int n;
    scanf("%d", &n);
    
    std::vector<int> val(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &(val[i]));
    }
    
    int ans1 = 0, ans2 = 0, max_diff = 0;
    for (int i = 1; i < n; ++i) {
      if (val[i - 1] > val[i]) {
        ans1 += val[i - 1] - val[i];
        max_diff = std::max(max_diff, val[i - 1] - val[i]);
      }
    }
    for (int i = 0; i < n - 1; ++i) {
      ans2 += std::min(max_diff, val[i]);
    }
    printf("Case #%d: %d %d\n", z, ans1, ans2);
  }
  return 0;
}
