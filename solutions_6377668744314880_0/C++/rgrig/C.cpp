#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

struct P {
  P(int x, int y) : x(x), y(y) {}
  int x, y;
};

int main() {
  int tests; scanf("%d",&tests);
  double pi = atan2(0, -1);
  double eps = 1e-9;
  for (int t = 1; t <= tests; ++t) {
    int n; scanf("%d", &n);
    vector<P> ps;
    for (int i = 0; i < n; ++i) {
      int x, y; scanf("%d %d",&x,&y);
      ps.push_back(P(x, y));
    }
    vector<int> logs;
    for (int i = 0; i < n; ++i) {
      if(0) printf("i %d\n", i);
      vector<double> as;
      for (int j = 0; j < n; ++j) if (i != j)
        as.push_back(atan2(ps[j].y-ps[i].y, ps[j].x-ps[i].x));
      sort(as.begin(), as.end());
      for (int j = 0; j < n - 1; ++j) as.push_back(2*pi + as[j]);
      if (0) {
        for (int j = 0; j < int(as.size()); ++ j) {
          printf(" %.03f",as[j]);
        }
        printf("\n");
      }
      int k = 0;
      int one_log = 0x3fffffff;
      for (int j = 0; j < n - 1; ++j) {
        if(0) printf("j %d\n", j);
        while (as[j] + pi - eps > as[k]) ++k;
        if(0) printf("k1 %d gives %d\n", k, k-j-1);
        one_log = min(one_log, k-j-1);
        while (as[j] + pi + eps > as[k]) ++k;
        if(0) printf("k2 %d gives %d\n", k,n-1-k+j);
        one_log = min(one_log, n-1-k+j);
      }
      if(0) printf("one_log %d\n", one_log);
      logs.push_back(one_log);
    }
    printf("Case #%d:\n", t);
    for (int i = 0; i < n; ++i) printf("%d\n", logs[i]);
  }
}
