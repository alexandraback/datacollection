//#define DEBUG_BUILD

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
  int N;
  scanf("%d", &N);
  DEBUG("N=%d\n", N);

  VI m(N);
  FOR(i,N) {
    scanf("%d", &m[i]);
    DEBUG(" %d", m[i]);
  }
  DEBUG("\n");
  int sum1 = 0;
  FOR(i,N-1) {
    if (m[i+1] < m[i]) {
      sum1 += m[i] - m[i+1];
      DEBUG("i=%d sum1 += %d = %d\n",i, m[i] - m[i+1], sum1);
    }
  }
  DEBUG("eat any =%d\n",sum1);

  int min = 0;
  int mini = 0;
  FOR(i,N-1) {
    if (m[i+1] < m[i] && m[i] - m[i+1] > min) {
      min = m[i] - m[i+1];
      mini = i;
    }
  }
  DEBUG("min=%d at %d\n", min, mini);

  int sum2 = 0;
  int blinches = m[0];
  FOR(i,N-1) {
    DEBUG("i= %d blinches=%d ", i, blinches);
    if (m[i] > blinches)
      blinches = m[i];
    if (blinches > min) {
      blinches -= min;
      sum2+= min;
      DEBUG(" +min = %d ", sum2);
    } else {
      sum2 += blinches;
      blinches = 0;
      DEBUG(" +blinches = %d ", sum2);
    }
    DEBUG("blinches = %d\n", blinches);
  }
  DEBUG("eat constant = %d\n", sum2);
  printf("%d %d\n", sum1, sum2);
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
