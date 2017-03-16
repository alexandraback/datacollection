#include <cassert>
#include <list>
#include <map>
#include <vector>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
  int T; scanf("%d\n", &T); for (int ii = 1; ii <= T; ++ii)
  {
    int R, C, N; scanf("%d %d %d\n", &R, &C, &N);
    int X = R * C; int cmin = -1;
    for (int bm = 0; bm < (1 << X); ++bm) if (__builtin_popcount(bm) == N)
    {
      vector<vector<bool> > V(R, vector<bool>(C, false));
      for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) if ((bm >> (i * C + j)) & 1) V[i][j] = true;
      int cc = 0;
      for (int i = 0; i < R; ++i)
      {
        for (int j = 1; j < C; ++j) if (V[i][j] && V[i][j-1]) cc++;
      }
      for (int i = 0; i < C; ++i)
      {
        for (int j = 1; j < R; ++j) if (V[j][i] && V[j-1][i]) cc++;
      }
      if (cmin == -1 || cmin > cc) cmin = cc;
    }
    printf("Case #%d: %d\n", ii, cmin);
  }
  return 0;
}
