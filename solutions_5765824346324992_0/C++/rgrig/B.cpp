#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stdint.h>
#include <inttypes.h>

using namespace std;

int main() {
  int tests; scanf("%d",&tests);
  for (int t = 1; t <= tests; ++t) {
    int b, n; scanf("%d %d", &b, &n);
    int64_t * m = (int64_t*)malloc(b * sizeof(int64_t));
    for (int i = 0; i < b; ++i) scanf("%" SCNd64,&m[i]);
    int64_t t1 = 1;
    while (1) {
      int64_t nn = 0;
      for (int i = 0; i < b; ++i) nn += (t1 + m[i] - 1) / m[i];
      if (0) printf("DBG t1 %" PRId64 " nn %" PRId64 "\n", t1, nn);
      if (nn >= n) { t1 /= 2; break; }
      t1 *= 2;
    }
    int64_t t2 = t1 / 2;
    while (t2 > 0) {
      int64_t nn = 0;
      for (int i = 0; i < b; ++i) nn += (t1 + t2 + m[i] - 1) / m[i];
      if (nn < n) t1 += t2;
      t2 /= 2;
    }
    if (0) printf("DBG t1 %" PRId64 "\n", t1);
    priority_queue<pair<int64_t,int> > q;
    for (int i = 0; i < b; ++i) {
      int d = (t1 + m[i] - 1) / m[i];
      n -= d;
      q.push(make_pair(-d*m[i], -i-1));
    }
    for (int i = 1; i < n; ++i) {
      auto p = q.top(); q.pop();
      if (0) printf("DBG %" PRId64 " %d\n", p.first, p.second);
      q.push(make_pair(p.first - m[-p.second-1], p.second));
    }
    auto p = q.top();
    free(m);
    printf("Case #%d: %d\n", t, -p.second);
  }
}
