#define DEBUG_BUILD

#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <assert.h>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define FOR(i, n) for(int i=0; i<(int)(n); i++)
#define FORD(i, n) for(int i=(n)-1; i>=0; i--)
#define FORI(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

#ifdef DEBUG_BUILD
#  define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#else
#  define DEBUG(...) do {} while (0)
#endif

typedef long double ld;
typedef signed   long long i64;
typedef unsigned long long u64;

// Types
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef map < int, int > MII;
typedef pair < int, int > PII;
typedef vector < VI > VII;

void DEBUG_VI(VI v) {
#ifdef DEBUG_BUILD
  FORI(it,v)
    DEBUG(" %d", *it);
  DEBUG("\n");
#endif
}

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

int main(int argc, char** argv);

int testi(int N, i64 t, VI& m) {
  int sum = 0;
  DEBUG("testi t=%d N=%d\n", t, N);
  FOR(i,m.size()) {
    int n=t/m[i];
    if (t%m[i] != 0)
      n++;
    DEBUG("  %d served %d\n", i, n);
    sum += n;
    if (sum >= N) {
      DEBUG(" %d >= %d\n", sum, N);
      return -1;
    }
  }
  DEBUG("  sum=%d served\n", sum);
  FOR(i,m.size()) {
    if (t%m[i]==0) {
      sum++;
      DEBUG("  sum=%d after %d\n", sum, i);
      if(sum == N) {
        DEBUG("  %d chosen!\n", i+1);
        printf("%d\n", i+1);
        return 0;
      }
    }
  }
  return 1;
}

void solve() {
  int B, N;
  scanf("%d %d", &B, &N);
  DEBUG("B=%d N=%d\n",B, N);

  VI m(B);
  int min = 100000;
  DEBUG("Barbers: ");
  FOR(i,B) {
    scanf("%d", &m[i]);
    DEBUG(" %d",m[i]);
    if (m[i] < min)
      min = m[i];
  }
  DEBUG("\nmin=%d\n", min);

  i64 imin = 0;
  i64 imax = (i64)N*min;
  DEBUG("imax %lld imin %lld\n", imax, imin);
  while (imax >= imin) {
    i64 imid = (imax+imin)/2;
    int result = testi(N, imid, m);
    DEBUG("imin=%d imid = %d imax=%d result = %d\n", imin, imid, imax, result);
    if (result == 0)
      return;
    if (result < 0) {
      imax = imid - 1;
    } else {
      imin = imid + 1;
    }
  }
}

int main(int argc, char** argv) {
  int TT;
  scanf("%d", &TT);
  for(int ii = 1; ii <= TT; ii++) {
    fprintf(stderr, "\n\nCase #%d\n", ii);
    printf("Case #%d: ", ii);
    solve();
  }
  return 0;
}
