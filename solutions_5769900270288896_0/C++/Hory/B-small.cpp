#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int flags[20];

int r = 0, c = 0, n = 0;

int solve()
{
  int apartments[20][20];
  int ans = 0;
  for(int i = 0, counts = 0; i < r; ++i)
    for(int j = 0; j < c; ++j)
      apartments[i][j] = flags[counts++];
  for(int i = 0; i < r; ++i)
    for(int j = 0; j < c; ++j)
    {
      if(apartments[i][j] == 0)
        continue;
      if(i + 1 < r && apartments[i + 1][j] == 1)
        ++ans;
      if(j + 1 < c && apartments[i][j + 1] == 1)
        ++ans;
    }
  return ans;
}

int dfs(int now, int counts)
{
  if(now == r * c)
  {
    if(counts != n)
      return 0xfffff;
    return solve();
  }
  int ans = dfs(now + 1, counts);
  if(counts < n)
  {
    flags[now] = 1;
    ans = min(ans, dfs(now + 1, counts + 1));
    flags[now] = 0;
  }
  return ans;
}

int main()
{
  int T = 0;
  scanf("%d", &T);
  for(int Case = 1; Case <= T; ++Case)
  {
    scanf("%d%d%d", &r, &c, &n);
    fill(flags, flags + r * c, 0);
    printf("Case #%d: %d\n", Case, dfs(0, 0));
  }
  return 0;
}
