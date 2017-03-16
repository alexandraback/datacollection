#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

const int N = 15;
struct Vec
{
  int x, y, id;
  ll cross(const Vec &rhs) const {
    return (ll)x*rhs.y-(ll)y*rhs.x;
  }
  bool operator<(const Vec &rhs) const {
    return x < rhs.x || x == rhs.x && y < rhs.y;
  }
  Vec operator-(const Vec &rhs) const {
    Vec ret;
    ret.x = x-rhs.x, ret.y = y-rhs.y;
    return ret;
  }
} a[N], b[N], c[N*2];
int res[N];

int monotone_chain(int n)
{
  sort(b, b+n);
  int size = 0;
  for (int i = 0; i < n; i++) {
    while (size > 1 && (c[size-1]-c[size-2]).cross(b[i]-c[size-2]) < 0) size--;
    c[size++] = b[i];
  }
  int size2 = size;
  for (int i = n-2; i >= 0; i--) {
    while (size2 > size && (c[size2-1]-c[size2-2]).cross(b[i]-c[size2-2]) < 0) size2--;
    c[size2++] = b[i];
  }
  return size2-1;
}

int main()
{
  int cases = ri();
  REP1(cc, cases) {
    int n = ri();
    REP(i, n) {
      a[i].x = ri();
      a[i].y = ri();
      a[i].id = i;
      res[i] = n;
    }
    REP(x, 1<<n) {
      int m = 0;
      REP(i, n)
        if (x & 1 << i)
          b[m++] = a[i];
      int mm = monotone_chain(m);
      REP(i, mm)
        res[c[i].id] = min(res[c[i].id], n-m);
    }
    printf("Case #%d:\n", cc);
    REP(i, n)
      printf("%d\n", res[i]);
  }
}
