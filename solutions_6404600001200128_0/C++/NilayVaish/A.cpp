#include <cassert>
#include <list>
#include <map>
#include <vector>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int main()
{
  int T; scanf("%d\n", &T); for (int ii = 1; ii <= T; ++ii)
  {
    int N; scanf("%d\n", &N); int first = 0, second = 0; int y = 0;
    vector<int> V;
    for (int i = 0; i < N; ++i)
    {
      int x; scanf("%d", &x);
      if (x < y) first += (y - x);
      y = x;
      V.push_back(x);
    }

    int mmd = 0; for (int i = 1; i < N; ++i)
    {
      if (V[i] < V[i-1]) mmd = max(mmd, V[i-1] - V[i]);
    }

    for (int i = 0; i < N-1; ++i)
    {
      if (V[i] < mmd) second += V[i];
      else second += mmd;
      //printf("%d, ", second);
    }
    printf("Case #%d: %d %d\n", ii, first, second);
  }
  return 0;
}
