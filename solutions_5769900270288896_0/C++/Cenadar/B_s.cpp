#pragma comment (linker, "/STACK:1073741824")
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <complex>

using namespace std;

#define SZ(x) (int((x).size()))
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define REPD(i, n) for (int (i) = (n); (i)--; )
#define FE(i, a) for (int (i) = 0; (i) < (int((a).size())); ++(i))
#define MEM(a, val) memset((a), val, sizeof(a))
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define PB push_back
#define PPB pop_back
#define ALL(c) (c).begin(), (c).end()
#define SQR(a) ((a)*(a))
#define MP(a,b) make_pair((a), (b))
#define XX first
#define YY second
#define GET_RUNTIME_ERROR *(int*)(NULL) = 1

typedef vector<int> vint;
typedef vector<long long> vLL;
typedef double dbl;
typedef long double ldbl;
typedef vector<pair<int, int> > vpii;
typedef long long LL;
typedef pair<int, int> pii;

bool m[20][20];

int count(int n) {
  int r = 0;
  while(n) {
    r += n & 1;
    n /= 2;
  }
  return r;
}

int solve(int r, int c, int n) {
  int all = 1 << (r*c);
  int res = INF;
  REP(mask, all) {
    if (count(mask) == n) {
      MEM(m, 0);
      REP(i, r*c) {
        if (mask & (1 << i)) {
          m[i/r][i%r] = true;
        }
      }

      int cur = 0;
      REP(i, 17) REP(j, 17) {
        if (m[i][j] && m[i][j + 1]) ++cur;
        if (m[i][j] && m[i + 1][j]) ++cur;
      }
      res = min(res, cur);
    }
  }
  return res;
}

int main() {
#ifdef    CENADAR_DEBUG
  freopen("input.txt", "r", stdin);
  freopen("/home/maksym/Downloads/B-small-attempt0.in", "r", stdin);
  freopen("output.txt", "w", stdout);
//  freopen("errput.txt", "w", stderr);
#else  // CENADAR_DEBUG
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif // CENADAR_DEBUG

  int T;
  cin >> T;
  REP(test, T) {
    int r, c, n;
    cin >> r >> c >> n;

    int ans = solve(r, c, n);

    printf("Case #%d: %lld\n", test + 1, ans);
  }

  return 0;
}
