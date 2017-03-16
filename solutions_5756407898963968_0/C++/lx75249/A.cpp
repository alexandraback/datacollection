#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#define see(x) cerr<<#x<<" = " << (x) << endl
using namespace std;
int first[4][4],second[4][4];
int ans[2];
void init()
{
  scanf("%d",ans);
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      scanf("%d",&first[i][j]);
  scanf("%d",ans+1);
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      scanf("%d",&second[i][j]);
}
void work()
{
  bool ok[17], ok2[17];
  memset(ok,0,sizeof(ok));
  memset(ok2,0,sizeof(ok2));
  int row=ans[0]-1;
  for(int i=0;i<4;i++)
    ok[first[row][i]] = true;
  row = ans[1]-1;
  for(int i=0;i<4;i++)
    ok2[second[row][i]] = true;
  for(int i=1;i<=16;i++)
    ok[i] = ok[i] && ok2[i];
  int count = 0;
  int res = 0;
  for(int i=1;i<=16;i++)
    if (ok[i]) count++, res=i;
  if (count == 0)
    printf("Volunteer cheated!\n");
  if (count == 1)
    printf("%d\n", res);
  if (count > 1)
    printf("Bad magician!\n");
}
int main()
{
  freopen("A-small-attempt0.in","r",stdin);
  freopen("out1","w",stdout);
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;t++)
  {
    init();
    printf("Case #%d: ", t);
    work();
  }
  return 0;
}
