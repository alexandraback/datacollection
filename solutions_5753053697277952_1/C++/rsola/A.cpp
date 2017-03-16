#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;
const int M = 1000000007;

int n;
int a[N];

int main() {
  freopen("A-large.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int C = 0, T;
  scanf("%d", &T);
  while (++C <= T) {
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]); sum += a[i];
    }
    printf("Case #%d:", C);
    while (sum) {
      int mx = 0, mxi = 0, mx2 = 0, mx2i = 0;
      for (int i = 0; i < n; i++) {
        if (mx < a[i]) { mx2 = mx; mx2i = mxi; mx = a[i]; mxi = i; }
        else if (mx2 < a[i]) { mx2 = a[i]; mx2i = i; }
      }
      if (a[mxi] - 1 <= (sum - 1) >> 1 && a[mx2i] <= (sum - 1) >> 1) {
        a[mxi]--; sum--; printf(" %c", mxi + 'A');
      } else if (a[mxi] - 2 <= (sum - 2) >> 1 && a[mx2i] <= (sum - 2) >> 1) {
        a[mxi] -= 2; sum -= 2; printf(" %c%c", mxi + 'A', mxi + 'A');
      } else {
        a[mxi]--; a[mx2i]--; sum -= 2; printf(" %c%c", mxi + 'A', mx2i + 'A');
      }
    }
    puts("");
  }
}
