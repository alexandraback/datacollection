#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int m[1024];

int main() {
  int t, T;
  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &m[i]);
    }

    int a = 0;
    for (int i = 0; i + 1 < n; ++i) {
      a += max(0, m[i] - m[i + 1]);
    }

    int mxd = 0;
    for (int i = 0; i + 1 < n; ++i) {
      mxd = max(mxd, m[i] - m[i + 1]);
    }
    long long z = 0;
    for (int i = 0; i + 1 < n; ++i) {
      if (m[i] <= mxd) {
        z += m[i];
      } else {
        z += mxd;
      }
    }
    printf("Case #%d: %d %lld\n", t, a, z);
  }
  return 0;
}
