#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <algorithm>
#include <string>
#include <cstring>

#define fori(i,b,e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back
#define add insert
#define all(a) (a).begin(), (a).end()
#define elsif else if
#define sz(a) ((int)(a).size())

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif
#define next next_sadasddsa

using namespace std;

typedef long long int int64;
typedef long double ldb;
typedef pair<int,int> pii;

inline void printInt(int a) { printf("%d", a); }
inline void printDbl(double a) { printf("%.10lf", a); }
inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }

int getAns(int n, int safe, int korn, int side) {
  int res = 0;
  n -= safe;
  if (n <= 0)
    return res;

  int d = min(korn, n);
  n -= d;
  res += d * 2;
  if (n <= 0)
    return res;

  d = min(side, n);
  n -= d;
  res += d * 3;

  res += n * 4;
  return res;
}

int solve() {
  int r = getInt(), c = getInt();
  if (r < c)
    swap(r,c);
  int n = getInt();
  if (c == 1) {
    int res = 0;
    n -= (r+1) / 2;
    if (n <= 0)
      return res;
    if (r % 2 == 0) {
      n--;
      res++;
    }
    res += n * 2;
    return res;
  }
  if (r * c % 2 == 0)
    return getAns(n, r * c / 2, 2, r + c - 4);
  int ans1 = getAns(n, r * c / 2, 4, r + c - 6);
  int ans2 = getAns(n, (r * c + 1) / 2, 0, r + c - 2);
  return min(ans1, ans2);
}

int main() {
#ifdef DEBUG
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
#endif
  srand(time(0));
  int T = getInt();
  fori(i,0,T) {
    printf("Case #%d: %d\n", i+1, solve());
  }
  return 0;
}