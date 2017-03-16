#include <stdio.h>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;

int T,n,m,nr,mask;
int sol=inf;
int dx[2]={0,1},dy[8]={1,0};

int check(int x)
{
    int nrc=0;
    for(int i=0;(x>>i);i++)
     if( ((x>>i)&1) ) nrc++;

    if(nrc==nr) return 1;
    return 0;
}

void solve()
{
    sol=inf;
    int cnt,ni,nj;

    mask=(1<<(n*m))-1;

    for(int k=0;k<=mask;k++)
     if(check(k))
     {
         cnt=0;
         for(int i=1;i<=n;i++)
          for(int j=1;j<=m;j++)
           if( (k>>( (i-1)*m+j-1 ))&1 )
           {
              for(int l=0;l<2;l++)
              {
                  ni=i+dx[l]; nj=j+dy[l];
                  if(ni<1 || ni>n || nj<1 || nj>m) continue;

                  if( (k>>( (ni-1)*m+nj-1 ))&1 ) cnt++;
              }

           }

        sol=min(sol,cnt);
     }
}

int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);

    scanf("%d",&T);
    for(int it=1;it<=T;it++)
    {
        scanf("%d%d%d",&n,&m,&nr);

        solve();
        printf("Case #%d: %d\n",it,sol);
    }

    return 0;
}
