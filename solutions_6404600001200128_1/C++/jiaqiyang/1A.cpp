#include <cstdio>
#include <algorithm>

const int N = 10000 + 10;

int tcase, n, m[N];

int main() {
  int tcase;
  scanf("%d", &tcase);
  for (int tid = 1; tid <= tcase; ++tid) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", m + i);
    int x = 0, y = 0, z = 0;
    for (int i = 1; i < n; ++i) {
      if (m[i] > m[i + 1]) {
        x += (m[i] - m[i + 1]);
        z = std::max(z, m[i] - m[i + 1]);
      }
    }
    for (int i = 1; i < n; ++i) y += std::min(z, m[i]);
    printf("Case #%d: %d %d\n", tid, x, y);
  }
  return 0;
}
