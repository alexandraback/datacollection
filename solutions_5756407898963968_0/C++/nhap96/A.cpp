#include <bits/stdc++.h>
#define FORE(i, c) for (__typeof ((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPD(i, n) for (int i = (int) (n) - 1; i >= 0; --i)
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define __ cerr <<
#define _ << " " <<
#define NL endl
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
typedef double DD;
typedef long double LD;
const LL LLINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-7;
inline const int &INT() { static int x; scanf("%d", &x); return x; }
inline const LL &LONG() { static LL x; scanf("%lld", &x); return x; }
template<class T> inline void MIN(T &a, const T &b) { if (b < a) a = b; }
template<class T> inline void MAX(T &a, const T &b) { if (b > a) a = b; }
// ---------------------------------------------------------------- //

int A[4][4], B[4][4];

int main() {
//  ios::sync_with_stdio(false);
//  freopen("in", "r", stdin);
  int TC = INT();
  REP(tc, TC) {
    printf("Case #%d: ", tc + 1);
    int x = INT(); --x;
    REP(i, 4) REP(j, 4) A[i][j] = INT();
    int y = INT(); --y;
    REP(i, 4) REP(j, 4) B[i][j] = INT();
    int c = 0, p = 0;
    REP(i, 4) REP(j, 4) if (A[x][i] == B[y][j]) ++c, p = A[x][i];
    if (c == 1) printf("%d\n", p);
    else if (c == 0) printf("Volunteer cheated!\n");
    else printf("Bad magician!\n");
  }

  return 0;
}
