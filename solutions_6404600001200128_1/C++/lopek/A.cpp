#include <cstdio>
#include <algorithm>
#include <assert.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int n;
    scanf("%d", &n);
    vector<int> M(n);
    for (int& m: M) {
      scanf("%d", &m);
    }

    int r1 = 0, r2 = 0, p2 = 0;
    for (int i = 0; i < n - 1; i++) {
      r1 += max(0, M[i] - M[i + 1]);
      p2 = max(p2, M[i] - M[i + 1]);
    }
    for (int i = 0; i < n - 1; i++) {
      r2 += min(p2, M[i]);
    }

    printf("Case #%d: %d %d\n", t, r1, r2);
  }
  return 0;
}
