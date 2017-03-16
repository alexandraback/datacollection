#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int ntc; scanf("%d", &ntc);
  REP(tc, ntc) {
    int n; scanf("%d", &n);
    int maks = 0, sum = 0;
    const int MAXN = 1e3 + 123;
    static int A[MAXN];

    int last = -123;
    REP(i, n) {
      int a; scanf("%d", &a); A[i] = a;
      if (last > a) {
        int t = abs(last-a);
        sum += t;
        maks = max(maks, t);
      }
      last = a;
    }

    int ans = 0;
    REP(i, n-1) ans += min(A[i], maks);

    printf("Case #%d: %d %d\n", tc+1, sum, ans);
    fflush(stdout);
  }
  return 0;
}   
