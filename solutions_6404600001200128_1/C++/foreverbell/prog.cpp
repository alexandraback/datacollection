
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
 
int n, a[11111];

int main() {
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
  int tests;
  read(tests);
  for (int tt = 1; tt <= tests; ++tt) {
    read(n);
    for (int i = 1; i <= n; ++i) {
      read(a[i]);
    }
    int ret1 = 0, ret2 = 0, rate = 0;
    for (int i = 2; i <= n; ++i) {
      ret1 += max(0, a[i - 1] - a[i]);
      rate = max(rate, a[i - 1] - a[i]);
    }
    for (int i = 1; i < n; ++i) {
      ret2 += min(rate, a[i]);
    }
    printf("Case #%d: %d %d\n", tt, ret1, ret2);
  }
  return 0;
}
