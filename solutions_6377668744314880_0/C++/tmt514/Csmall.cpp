#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

int T;
int cs;
const int N = 1005;
LL a[N], b[N]; int n;
LL x[N], y[N], idx[N]; int m;
LL ans[N];

void go() {
  for(int i=0;i<m;i++) {
    int flag=0;
    for(int j=0;j<m && !flag;j++) {
      if(i==j) continue;
      LL dx = x[j] - x[i];
      LL dy = y[j] - y[i];
      int bad = 0;
      for(int k=0;k<m;k++) {
        LL ex = x[k] - x[i];
        LL ey = y[k] - y[i];
        if (dx * ey - ex * dy < 0) bad = 1;
      }
      flag |= !bad;
    }
    if(flag) ans[idx[i]] = min((LL)ans[idx[i]], (LL)n-m);
  }
}

void solve() {
  scanf("%d", &n);
  for(int i=0;i<n;i++) scanf("%lld%lld", &a[i], &b[i]);
  for(int i=0;i<n;i++) ans[i] = n-1;
  for(int i=1;i<(1<<n);i++) {
    m = 0;
    for(int j=0;j<n;j++) if(i&(1<<j)) { x[m] = a[j]; y[m] = b[j]; idx[m] = j; m++; }
    go();
  }
  printf("Case #%d:\n", cs);
  for(int i=0;i<n;i++)
    printf("%lld\n", ans[i]);
}

int main(void) {
  scanf("%d", &T);
  for(cs=1;cs<=T;cs++) solve();
  return 0;
}
