#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;

typedef long long int64 ;
typedef unsigned long long uint64 ;
typedef pair<int, int> pint ;
typedef pair<int64, int64> pint64 ;
typedef vector<int> vint ;

#define px first
#define py second

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))

#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define REPD(i, n) for (int i = (n) ; i >= 0 ; i --)
#define FOR(i, a, b) for (int i = (a) ; i < (b) ; i ++)
#define FORD(i, a, b) for (int i = (a) ; i >= (b) ; i --)

#define MUL64(x, y) (((int64) (x)) * ((int64) (y)))
#define MULMOD(x, y, modul) (MUL64(x, y) % modul)
#define MUL(x, y) MULMOD(x, y, modul)
#define ADD(reg, val) { reg += val ; if (reg >= modul) reg -= modul ; }

#define SET(v, val) memset(v, val, sizeof(v)) ;
#define SIZE(v) ((int) (v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) { sort(ALL(v)) ; }
#define RSORT(v) { SORT(v) ; REVERSE(v) ; }
#define REVERSE(v) { reverse(ALL(v)) ; }
#define UNIQUE(v) unique((v).begin(), (v).end())
#define RUNIQUE(v) { SORT(v) ; (v).resize(UNIQUE(v) - (v).begin()) ; }

//#define BIG
string PROBLEM = "B" ;

#ifdef BIG
ifstream in((PROBLEM + "-large2.in").c_str()) ; ofstream out((PROBLEM + "-large2.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif


int b, n, m [1888];

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  FOR(test, 1, numTests + 1) {
    in >> b >> n;

    priority_queue<pint> q;
    REP(i, b) { in >> m [i]; }
    int64 low = 0LL, high = MUL64(n, 100001LL), mid, best = 0LL, cur;
    while (low <= high) {
      mid = low + (high - low) / 2;
      cur = 0LL;
      REP(i, b) cur += mid / m [i];
      if (cur < n - 200000) { best = MAX(best, mid); low = mid + 1; }
      else high = mid - 1;
    }
    int64 skipped = 0LL;
    REP(i, b) {
      int64 curskip = best / m [i];
      skipped += curskip;
      q.push(pint64(-(curskip * m [i]), -i));
    }

    // q.push(pint(0, -i));
    int last = -1;
    FOR(i, skipped, n) {
      pint top = q.top(); q.pop();
      int t = -top.first;
      last = -top.second;
      q.push(pint(-(t + m [last]), -last));
    }

    cout << test << ":" << (last + 1) << endl;
    out << "Case #" << test << ": " << (last + 1) << endl ;
  }

  in.close() ;
  out.close() ;

  return 0;
}
