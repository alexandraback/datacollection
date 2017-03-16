// {{{ include
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
// }}}

using namespace std;

typedef long long ll;
inline int in(){int x;scanf("%d",&x);return x;}

int dp[16][16][2];

int main()
{
  int T = in();
  for (int t = 1; t <= T; t++){
    memset(dp, 0, sizeof(dp));
    int R = in(), C = in(), N = in();
    int B = R * C;
    int mini = 1 << 29;
    for (int i = 0; i < (1 << B); i++){
      if (__builtin_popcount(i) != N) continue;
      int score = 0;
      for (int y = 0; y < R; y++){
        for (int x = 0; x < C; x++){
          int yx = y * C + x;
          if (!((i >> yx) & 1)) continue;
          if (y != 0) score += (i >> (y * C + x - C)) & 1;
          if (x != 0) score += (i >> (y * C + x - 1)) & 1;
        }
      }
      mini = min(mini, score);
    }
    printf("Case #%d: %d\n", t, mini);
  }

  return 0;
}
