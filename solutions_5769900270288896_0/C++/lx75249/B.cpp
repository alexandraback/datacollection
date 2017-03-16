#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int r, c, n;

int mat[20][20];

int count1(int opt)
{
  int ans = 0;
  for(;opt;opt>>=1)
    ans += opt&1;
  return ans;
}

int work()
{
  int ans = r*c*100;
  for(int opt=0; opt<1<<(r*c); ++opt)
  {
    if (count1(opt) != n)
      continue;
    for(int i=0; i<r*c; ++i)
    {
      int x = i/c+1;
      int y = i%c+1;
        mat[x][y] = (opt>>i)&1;
    }
    int tmp = 0;
    for(int i=1; i<=r; ++i)
      for(int j=1; j<=c; ++j)
        if (mat[i][j])
        {
          if (mat[i-1][j])
            ++tmp;
          if (mat[i][j-1])
            ++tmp;
        }
    if (tmp < ans)
      ans = tmp;
  }
  return ans;
}

int main()
{
  //freopen("in","r",stdin);
  int T;
  cin >> T;
  for(int i=1; i<=T; ++i)
  {
    cin >> r >> c >> n;
    printf("Case #%d: %d\n", i, work());
  }
}
