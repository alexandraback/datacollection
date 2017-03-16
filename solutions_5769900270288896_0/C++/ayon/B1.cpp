#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<assert.h>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<limits.h>

using namespace std;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define EPS 1e-9
#define asdf exit(0);
#define AB(a) ((a)<(0) ? (-(a)) : (a))
#define EQ(a,b) ( (fabs((a)-(b))<EPS) ? (1) : (0))





typedef long long LL;
//typedef __int64 LL;


int mark[20][20];
int ret;
int temp;
int n,m;
int mem[20][20][20];


void bttk(int r,int c,int cnt)
{
  if(r==n)
  {
    mem[n][m][cnt]=min(mem[n][m][cnt],temp);
    return;
  }

  if(c==m)
  {
    bttk(r+1,0,cnt);
    return;
  }

  int now=0;
  if(r && mark[r-1][c]) now++;
  if(c && mark[r][c-1]) now++;

  temp+=now;
  mark[r][c]=1;
  bttk(r,c+1,cnt+1);
  mark[r][c]=0;
  temp-=now;

  bttk(r,c+1,cnt);
}



void get(int a,int b)
{
  ret=3000;
  memset(mark,0,sizeof(mark));
  n=a;
  m=b;
  bttk(0,0,0);
}



int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int i,j,k,n,m;

    for(i=0;i<20;i++)
    for(j=0;j<20;j++)
    for(k=0;k<20;k++)
    mem[i][j][k]=1000000;



    for(i=1;i<=16;i++)
    for(j=1;i*j<=16;j++)
    {
      get(i,j);
    }


    int T;
    scanf("%d",&T);

    for(int cs=1;cs<=T;cs++)
    {
      printf("Case #%d: ",cs);
      int val1,val2,N;
      scanf("%d %d %d",&val1,&val2,&N);
      printf("%d\n",mem[val1][val2][N]);
    }




    return 0;
}
