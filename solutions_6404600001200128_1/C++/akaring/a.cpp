#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void checkMin(T &a, T b) { if(b<a) a=b; }
template<typename T> inline void checkMax(T &a, T b) { if(a<b) a=b; }
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for (int i=0;i<int(n);++i)
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    int n, a1 = 0, a2 = 0, b = 0;
    scanf("%d", &n);
    VI a(n, 0);
    REP (i, n) {
      scanf("%d", &a[i]);
      if (i > 0) {
        a1 += max(a[i - 1] - a[i], 0);
        checkMax(b, a[i - 1] - a[i]);
      }
    }
    REP (i, n) {
      if (i > 0) {
        a2 += min(b, a[i - 1]);
      }
    }
    printf("Case #%d: %d %d\n", index, a1, a2);
  }
  return 0;
}
