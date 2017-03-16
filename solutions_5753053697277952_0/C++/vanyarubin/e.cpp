#define DE_BUILD

#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <boost/regex.hpp>
#include <boost/tokenizer.hpp>

using namespace std; using namespace boost;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define found(x,e) (x.find(e) != x.end())
#define FOR(i, n) for(int i=0; i<(int)(n); i++)
#define FORD(i, n) for(int i=(n)-1; i>=0; i--)
#define FORI(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

#ifdef DE_BUILD
#  define DE(...) fprintf(stderr, __VA_ARGS__)
#  define DI FOR(indenti,indent) DE("  ")
#else
#  define DE(...) do {} while (0)
#  define DI do {} while (0)
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
typedef vector < PII > VPII;
typedef set <PII> SPII;
typedef vector < VI > VVI;
typedef vector<SI> G;
void DE_VI(VI v) {
#ifdef DE_BUILD
  FORI(it,v) DE(" %d", *it); DE("\n");
#endif
}

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;
const i64 IMAX = LLONG_MAX;
const u64 UMAX = ULLONG_MAX;
//#include "lib.cpp"

int main(int argc, char** argv);

void DE_VPII(VPII v) {
#ifdef DE_BUILD
  FOR(i,v.size()) {
    DE(" %d %c", v[i].first, v[i].second+'A');
  }
 DE("\n");
#endif
}

void solve() {
  int N;
  scanf("%d", &N);
  fprintf(stderr, "N = %d\n",N);
  //MII P;
  VPII numparty;
  FOR(i,N) {
    int num;
    scanf("%d", &num);
    //P[i] = num;
    numparty.pb(mp(num,i));
  }
  //DE("Senators: "); DE_VI(P);
  sort(all(numparty));
  reverse(all(numparty));

  DE("Numparty: "); DE_VPII(numparty);

  int max = numparty[0].first;
  int max2 = numparty[1].first;
  DE("max = %d, max2 = %d\n", max, max2);
  FOR(i,max-max2) {
    printf(" %c", numparty[0].second + 'A');
  }
  for(int j = 2; j<numparty.size(); j++) {
    FOR(k,numparty[j].first) {
      printf(" %c", numparty[j].second+'A');
    }
  }
  FOR(i,max2) {
    printf(" %c%c",numparty[0].second + 'A', numparty[1].second+'A');
  }
  printf("\n");
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
