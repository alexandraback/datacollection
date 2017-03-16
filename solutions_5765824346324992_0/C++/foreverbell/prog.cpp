
#include <bits/stdc++.h>
 
typedef long long LL;
const int maxint = 0x7f7f7f7f, mod = 1000000007;
const double eps = 1e-8, pi = acos(-1.0);
 
void read() { }
template<typename... T> void read(int &h, T &... t) { scanf("%d", &h); read(t...); }
template<typename... T> void read(LL &h, T &... t) { scanf("%lld", &h); read(t...); }
template<typename... T> void read(double &h, T &... t) { scanf("%lf", &h); read(t...); }
 
#define abs _abs
template<typename T> T abs(const T &h) { return h > 0 ? h : -h; }
 
using namespace std;

int nth, n, a[1111];

LL count(LL mid) {
  LL cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += mid / a[i];
    if (mid % a[i] != 0) ++cnt;
  }
  return cnt;
}

int main() {
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);
  int tests;
  read(tests);
  for (int tt = 1; tt <= tests; ++tt) {
    read(n, nth);
    for (int i = 1; i <= n; ++i) {
      read(a[i]);
    }
    LL lo = 0, hi = 100000ll * nth;
    while (lo < hi) {
      LL mid = (lo + hi) / 2 + 1, cnt = 0;
      cnt = count(mid);
      if (cnt < nth) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    LL k = count(lo);
    for (int i = 1; i <= n; ++i) {
      if (lo % a[i] == 0) {
        ++k;
        if (k == nth) {
          printf("Case #%d: %d\n", tt, i);
          break;
        }
      }
    }
  }
  return 0;
}
