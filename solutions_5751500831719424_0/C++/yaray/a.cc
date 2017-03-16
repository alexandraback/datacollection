#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <map>
#include <set>
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

typedef vector<int> VI;
typedef pair<int, int> PII;

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

const int N = 110;
char a[N][N], b[N];
int l[N], c[N][N], g[N];

bool cmp(int x, int y)
{
  if (l[x] != l[y]) return false;
  REP(i, l[x])
    if (a[x][i] != a[y][i])
      return false;
  return true;
}

int main()
{
  int cases = ri();
  REP1(cc, cases) {
    int n = ri();
    REP(i, n) {
      scanf("%s", b);
      l[i] = 0;
      for (int j = 0, k; b[j]; j = k) {
        for (k = j; b[j] == b[k]; k++);
        a[i][l[i]] = b[j];
        c[i][l[i]] = k-j;
        l[i]++;
      }
    }
    bool tak = true;
    FOR(i, 1, n)
      if (! cmp(0, i)) {
        tak = false;
        break;
      }
    if (! tak)
      printf("Case #%d: Fegla Won\n", cc);
    else {
      int ans = 0;
      REP(i, l[0]) {
        REP(j, n)
          g[j] = c[j][i];
        sort(g, g+n);
        int mi = g[n/2];
        REP(j, n)
          ans += abs(mi-c[j][i]);
      }
      printf("Case #%d: %d\n", cc, ans);
    }
  }
}
