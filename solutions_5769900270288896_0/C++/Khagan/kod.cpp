//Khagan

#include <algorithm>
#include <string.h>
#include <stdio.h>
#define  fi        first
#define  se        second
#define  inf       1 << 30
using    namespace std;
typedef  pair<int,int> pi;

int T,R,C,N;

pi g(int x)
{
  int c1=0,c2=0;
  for(int i=0 ; i<C ; i++)
    if(x&(1<<i))
    {
      c1++;
      if(x&(1<<(i+1)))
        c2++;
    }
  return pi(c1,c2);
}

int h(int b1 , int b2)
{
  int cnt=0;
  for(int i=0 ; i<C ; i++)
    if(b1&(1<<i))
      if(b2&(1<<i))
        cnt++;
  return cnt;
}

int f()
{
  if(R<C) swap(R,C);
  int dp[R+1][N+1][(1<<C)];
  memset(dp,-1,sizeof(dp));
  for(int i=0 ; i<(1<<C) ; i++)
  {
    pi tmp=g(i);
    if(tmp.fi>N) continue;
    dp[1][tmp.fi][i]=tmp.se;
  }
  for(int r1=2 ; r1<=R ; r1++)
    for(int n1=0 ; n1<=N ; n1++)
      for(int b1=0 ; b1<(1<<C) ; b1++)
      {
        pi tmp=g(b1);
        if(tmp.fi>n1) continue;
        for(int b2=0 ; b2<(1<<C) ; b2++)
        {
          pi tmp2=g(b2);
          if(tmp.fi+tmp2.fi>n1) continue;
          if(dp[r1-1][n1-tmp.fi][b2]==-1) continue;
          int cnt=h(b1,b2);
          int cost=dp[r1-1][n1-tmp.fi][b2]+cnt+tmp.se;
          if(dp[r1][n1][b1]==-1) dp[r1][n1][b1]=cost;
          else                   dp[r1][n1][b1]=min(dp[r1][n1][b1],cost);
        }
      }
  int res=inf;
  for(int i=0 ; i<(1<<C) ; i++)
    if(dp[R][N][i]!=-1)
      res=min(res,dp[R][N][i]);
  return res;
}

int main()
{
  freopen("B-small-attempt0.in","r",stdin);
  freopen("cikti.txt","w",stdout);
  scanf("%d",&T);
  for(int t=1 ; t<=T ; t++)
  {
    scanf("%d%d%d",&R,&C,&N);
    printf("Case #%d: %d\n",t,f());
  }
  return 0;
}
