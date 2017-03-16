#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
#include <complex>
using namespace std;

typedef long long int int64;

#define EPS 10e-9
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

int64 v[1200];

int main()
{
  int t;
  scanf("%d", &t);
  int64 c, n;
  REP(k, t) {
    scanf("%lld %lld", &c, &n);
    REP(i, c) {
      scanf("%lld", &v[i]);
    }
    int64 a = 0, b = 200000000000000LL;
    int res = 0;
    while (1) {
      if (a > b) {
        break;
      }
      int64 t = (a + b) / 2;
      int64 x = 0;
      REP(i, c) {
        x += t / v[i] + 1;
      }
      if (x >= n) {
        int f = x - n;
        for (int i = c - 1; i >= 0; i--) {
          if (t % v[i] == 0) {
            if (f == 0) {
              res = i + 1;
              break;
            }
            f--;
          }
        }
        b = t - 1;
      }
      else {
        a = t + 1;
      }
    }
    printf("Case #%d: %d\n", k+1, res);
  }
  return 0;
}
