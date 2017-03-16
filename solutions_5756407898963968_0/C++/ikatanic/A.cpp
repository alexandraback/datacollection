#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

int main(void) {
  int T;
  scanf("%d", &T);
  for (int tp = 1; tp <= T; ++tp) {
    static int a[16];
    REP(i, 16) a[i] = 0;

    REP(it, 2) {
      int row, x;
      scanf("%d", &row); --row;
      REP(i, 4) REP(j, 4) {
        scanf("%d", &x); --x;
        if (i == row) a[x]++;
      }
    }
    
    int cnt = 0, ind = -1;
    REP(i, 16)
      if (a[i] == 2) cnt++, ind = i;
    
    printf("Case #%d: ", tp);
    if (cnt == 1) printf("%d", ind+1);
    if (cnt > 1) printf("Bad magician!");
    if (cnt == 0) printf("Volunteer cheated!");
    printf("\n");
  }
  return 0;
}
