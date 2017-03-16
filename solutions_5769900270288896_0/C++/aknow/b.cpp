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

int R, C, N;


int count(bool pattern[]) {
  int result = 0;

  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c) {
      int current = r * C + c;
      if (!pattern[current]) continue;

      if (c != C-1) {
        int right = current + 1;
        if (pattern[right]) result++;
      }

      if (r != R-1) {
        int down = current + C;
        if (pattern[down]) result++;
      }
    }

  return result;
};

int run() {
  if (N == 0 || N == 1) return 0;

  int total = R * C;
  bool pattern[total];
  fill_n(pattern, total, false);
  for (int i = total - N; i < total; ++i) {
    pattern[i] = true;
  }

  int best = total * 2;
  do {
    best = min(best, count(pattern));
  } while (next_permutation(pattern, pattern + total));

  return best;
}

int main() {
    int caseN;
    scanf("%d", &caseN);

    for (int cc = 1; cc <= caseN; ++cc) {
        printf("Case #%d: ", cc);

        cin >> R >> C >> N;
        cout << run();

        printf("\n");
    }

    return 0;
}
