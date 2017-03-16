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
#include <ctime>

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
string PROBLEM = "C" ;

#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif

#define PI 3.14159265358979323
#define EPS 1e-9
typedef pair<double, int> pinfo;

int n, x [3888], y [3888];
vector<double> v;

int cnt(double low, double high) {
  int ilow = lower_bound(v.begin(), v.end(), low + EPS) - v.begin();
  int ihigh = upper_bound(v.begin(), v.end(), high - EPS) - v.begin();
  //cout << "cnt(" << low << "," << high <<") ->" << ilow << "," << ihigh << endl;
  return ihigh - ilow;
}

int f(double low, double high) {
  if (low > high + EPS) {
    int tmp1 = cnt(low, 2.0 * PI + 2.0 * EPS), tmp2 = cnt(-2.0 * EPS, high);
    //cout << "f(" << low << "," << high << ") ->" << tmp1 << "," << tmp2 << endl;
    return tmp1 + tmp2;
  } else {
    int tmp = cnt(low, high);
    //cout << "f(" << low << "," << high << ") ->" << tmp << endl;
    return tmp;
  }
}

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  FOR(test, 1, numTests + 1) {
    in >> n;
    REP(i, n) in >> x [i] >> y [i];

    out << "Case #" << test << ":" << endl;
    REP(i, n) {
      v.clear();
      REP(j, n) if (i != j) {
        double dx = x [j] - x [i], dy = y [j] - y [i];
        double at2 = atan2(dy, dx);
        if (at2 < -1e-9) at2 += 2 * PI;
        v.push_back(at2);
        //cout << test << ":" << i << ":" << x [i] << "," << y [i] << "->" << j << ":" << x [j] <<"," << y [j] << "->" << dx << "," << dy << "," << at2 << endl;
      }
      sort(v.begin(), v.end());
      int ret = n - 1;
      REP(iv, SIZE(v)) {
        double cur = v [iv], icur = cur + PI;
        if (icur > 2.0 * PI - EPS) icur -= 2.0 * PI;
        int c1 = f(cur, icur), c2 = f(icur, cur);
        //cout << test << ":" << i << ":" << x [i] << "," << y [i] << "->" << iv << "," << v [iv] << "->" << cur << "," << icur << "->" << c1 << "," << c2 << endl;
        ret = MIN(ret, MIN(c1, c2));
      }
      out << ret << endl;
    }
  }

  in.close() ;
  out.close() ;

  return 0;
}
