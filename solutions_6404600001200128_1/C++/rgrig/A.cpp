#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int tests; scanf("%d",&tests);
  for (int t = 1; t <= tests; ++t) {
    int n; scanf("%d", &n);
    int * m = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d",&m[i]);
    int r1 = 0;
    for (int i = 1; i < n; ++i) r1 += max(0, m[i-1] - m[i]);
    int delta = 0;
    for (int i = 1; i < n; ++i) delta = max(delta, m[i-1] - m[i]);
    int r2 = 0;
    for (int i = 1; i < n; ++i) r2 += min(delta, m[i-1]);
    free(m);
    printf("Case #%d: %d %d\n", t, r1, r2);
  }
}
