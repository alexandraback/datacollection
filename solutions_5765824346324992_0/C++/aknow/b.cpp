#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en)  for(int i=(st); i<=(int)(en); i++)
#define Forn(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

// Types
typedef long double ld;
typedef signed   long long i64;
typedef signed   long long ll;
typedef unsigned long long u64;
typedef unsigned long long ull;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

//#define debug(...)
#define debug printf

i64 N;
int B;
vector<int> mk;

i64 ongoing(i64 min) {
  if (min < 0) return 0;

  i64 sum = 0;
  for (auto m : mk) {
    sum += min / m + 1;
    if (sum >= N) return N;
  }
  return sum;
}

int findnth(int nth) {
  i64 minTime = (i64)*min_element(mk.begin(), mk.end()) * (nth-1) + 1;

  i64 lo = -1;
  i64 hi = minTime;

  //cout << hi << endl;
  //cout << ongoing(hi) << endl;
  assert(ongoing(hi) >= nth);

  while (lo < hi) {
    i64 mid = lo + (hi-lo + 1)/2;
    //cout << mid << ": " << ongoing(mid) << endl;
    if (ongoing(mid) >= nth) {
      hi = mid-1;
    } else {
      lo = mid;
    }
  }

  //cout << lo << " " << ongoing(lo) << " - " << ongoing(lo+1) << endl;
  assert(ongoing(lo) < nth);
  assert(ongoing(lo+1) >= nth);

  i64 now = ongoing(lo);
  for (int i = 0; i < B; ++i) {
    i64 diff = (lo + 1)/mk[i] - lo/mk[i];
    now += diff;
    if (now >= nth) {
      return i + 1;
    }
  }

  return -1;
}

int main() {
    int caseN;
    scanf("%d", &caseN);

    for (int cc = 1; cc <= caseN; ++cc) {
        printf("Case #%d: ", cc);

        mk.clear();
        cin >> B >> N;
        int tmp;
        for (int i = 0; i < B; ++i) {
          cin >> tmp;
          mk.push_back(tmp);
        }

        if (N == 1) {
          cout << 1;
        } else {
          cout << findnth(N);
          // index + 1
        }

        printf("\n");
    }

    return 0;
}
