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

void solve() {
  int R,C,N;
  scanf("%d %d %d", &R, &C, &N);
  if(R>C)
    swap(R,C);
  DEBUG("R=%d C=%d N=%d\n", R,C,N);

  int rhm = R/2;
  int rhp = R-rhm;
  int chm = C/2;
  int chp = C-chm;

  int minN = rhp*chp + rhm*chm;
  DEBUG("  minN = %d\n", minN);
  if (N <= minN) {
    DEBUG(" less than half - 0 \n");
    printf("0\n");
    return;
  }

  int total_walls = (C-1)*R + (R-1)*C;
  DEBUG("total walls = %d\n", total_walls);
  int s = R*C - N;
  DEBUG("spaces = %d\n", s);

  if (R == 1) {
    int result = total_walls - s*2;
    DEBUG("R==1: %d\n", result);
    printf("%d\n", result);
    return;
  }

  // can not touch boundaries
  int r2 = R-2;
  int c2 = C-2;
  int r2m = r2/2;
  int r2p = r2-r2m;
  int c2m = c2/2;
  int c2p = c2-c2m;
  int inner_spaces = r2p*c2p+r2m*r2m;
  DEBUG(" inner spaces %d\n", inner_spaces);
  if (s <= inner_spaces) {
    int result = total_walls - s*4;
    DEBUG(" less than inner spaces - %d \n", result);
    printf("%d\n", result);
    return;
  }
  s -= inner_spaces;

  // have to touch 3 boundary(s)
  int b3row = (C-2)/2;
  int b3col = (R-2)/2;
  int b3 = 2*b3row + 2*b3col;
  DEBUG(" b3 %d\n", b3);
  if (s <= b3) {
    int result = total_walls - inner_spaces*4 -(s-b3)*3;
    DEBUG(" less than b3 spaces = %d \n", result);
    printf("%d\n", result);
    return;
  }
  // have to touch 2 boundary(s)

  s -= b3;
  DEBUG("  sl = %d\n", s);
  assert(s<=4);
  int r = total_walls - inner_spaces*4 - b3*3 - s*2;
  DEBUG(" less than inner spaces - %d \n", r);
  printf("%d\n", r);
  return;
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
