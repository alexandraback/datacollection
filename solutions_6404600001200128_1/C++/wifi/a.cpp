#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;


int main() {
  int n, t, m[1100], ans1, ans2, mm;
  scanf("%d%",&t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d%",&n);
    mm = 0;
    for(int i = 0; i<n; i++) {
      scanf("%d", m+i);
      if(i > 0) {
        if(mm < m[i-1]-m[i])
          mm = m[i-1]-m[i];
      }
    }
    ans1 = ans2 = 0;
    for(int i = 1; i<n; i++) {
      ans1 += max(0, m[i-1]-m[i]);
      ans2 += min(mm, m[i-1]);
    }
    printf("Case #%d: %d %d\n", tc, ans1, ans2);
  }
  return 0;
}