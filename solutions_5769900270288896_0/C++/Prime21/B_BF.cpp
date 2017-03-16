#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#define REP(I,A,B) for (int I=A,END=B;I<=END;I++)
#define REPD(I,A,B) for (int I=A,END=B;I>=END;I--)
#define RI(X) scanf("%d",&X)
#define RS(X) scanf("%s",X)
#define RD(X) scanf("%lf",&X)
#define RLL(X) scanf("%I64d",&X)
#define GCH getchar()
#define PCH(X) putchar(X)
#define MS(X,Y) memset(X,Y,sizeof(X))
#define MC(X,Y,var,len) memcpy(X,Y,sizeof(var)*(len))
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
int t;
int tot=0;
int r,c,n;
int map[16][16]={0};
void open()
{
  freopen("B.in","r",stdin);
  freopen("B_BF.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}
void init()
{
  RI(r);
  RI(c);
  RI(n);
}
void dfs(int deep,int i,int j,int ans)
{
  if (ans>tot)
    return ;
  if (deep==n)
  {
    if (ans<tot)
      tot=ans;
    return ;
  }
  if (i==r+1)
    return ;
  if (r*c-(i-1)*c-j+1>=n-deep) //ªπø…“‘ 
  {
    map[i][j]=1;
    if (map[i-1][j]==1)
      ans++;
    if (map[i][j-1]==1)
      ans++;
    if (j==c)
      dfs(deep+1,i+1,1,ans);
    else 
      dfs(deep+1,i,j+1,ans);
    if (map[i-1][j]==1)
      ans--;
    if (map[i][j-1]==1)
      ans--;
    map[i][j]=0;
    if (j==c)
      dfs(deep,i+1,1,ans);
    else 
      dfs(deep,i,j+1,ans);
  }
}
int main()
{
  open();
  int _=0;
  RI(_);
  REP(__,1,_)
  {
    init();
    tot=r*(c-1)+(r-1)*c;
    dfs(0,1,1,0);
    printf("Case #%d: %d\n",__,tot);
  }
  close();
  return 0;
}

