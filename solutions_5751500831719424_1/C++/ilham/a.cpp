#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long LL;
typedef vector<LL> vl;
typedef vector<double> vd;

#define FOR(i,n) for (i = 0; i < (n); i++)
#define FORI(i,a,b) for (i = (a); i <= (b); i++)
#define FORD(i,a,b) for (i = (a); i >= (b); i--)
#define FOREACH(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, -1, sizeof(a))
#define SZ(a) (a.size())
#define MP(a, b) make_pair(a, b)
#define SHL(a,b) ((a) << (b))
#define SHR(a,b) ((a) >> (b))
#define FI first
#define SE second
#define PB push_back

template<class T> int bitcount(T a) { int x = 0; while (a) { x += (a & 1); a >>= 1; } return x; }
template<class T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline T sqr(T a) { return a * a; } // NOTE: T must be enough to save sqr!
inline int parity(LL a) { return __builtin_parityl(a); }
inline int parity(int a) { return __builtin_parity(a); }
template<class T> T s2type(string s) { T res; istringstream in(s); in >> res; return res; }
template<class T> string toString(T n) { ostringstream out; out << n; return out.str(); }

const double PI = acos(-1.0);
const double EPS = 1e-11;

char st[128][256];
int ln[128];
char aa[128];
char cons[256];
int ct[128][256];
int n, cc;

void shortened(char* from, int l, char* to)
{
  int tmp = 0, i;
  to[0] = from[0];
  FOR(i, l - 1) if (to[tmp] != from[i + 1]) to[++tmp] = from[i + 1];
}

int doit()
{
  int i, j, k, l, curbest, cur, total;
  // check possible
  ZERO(cons);
  FOR(i, n) ln[i] = strlen(st[i]);
  shortened(st[0], ln[0], cons);
//  fprintf(stderr, "cons == %s\n", cons);
  FOR(i, n - 1)
  {
    FOR(j, 128) aa[j] = 0;
    shortened(st[i + 1], ln[i + 1], aa);
//    fprintf(stderr, "res == %s\n", aa);
    if (strcmp(aa, cons) != 0) return -1;
  }
  l = strlen(cons);

  //counting
  ZERO(ct);
  FOR(i, n)
  {
    k = 0;
    ct[i][0] = 1;
    FOR(j, ln[i] - 1)
      if (st[i][j + 1] == cons[k])
        ct[i][k]++;
      else
        ct[i][++k] = 1;
    // sanity check:
    assert(k == l - 1);
  }

  // get the nicest number!
  total = 0;
  FOR(i, l)
  {
    curbest = 1000000;
    FOR(j, 101) {
      cur = 0;
      FOR(k, n)
        cur += abs(ct[k][i] - (j + 1));
      if (cur < curbest) curbest = cur;
    }
    total += curbest;
  }

  return total;
}

int main()
{
  int T, t, i, j;
  scanf("%d", &T);
  FOR(t, T)
  {
    scanf("%d", &n);
    FOR(i, n) {
      scanf("%s", st[i]);
    }
    j = doit();
    if (j != -1)
      printf("Case #%d: %d\n", t + 1, j);
    else
       printf("Case #%d: Fegla Won\n", t + 1);
  }
  return 0;
}

