#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
using namespace std;
int n,m,a,b,c,d,x;
char ch;
int t[50][50];
void solve()
  {
  scanf("%d%d%d",&n,&m,&x);
  FOR(i,0,n+1)
    FOR(j,0,m+2)
      t[i][j]=0;
  int allres=1000;
  REP(i,1<<(n*m))
    {
    int xx=0;
    int s=0;
    FOR(j,1,n)
      FOR(u,1,m)
        {
        t[j][u]=(i&(1<<xx))>0;
        s+=t[j][u];
        xx++;
        }
    if(s!=x)continue;
    int res=0;
    FOR(j,1,n)
      FOR(u,1,m)
        {
        if(t[j][u]&&t[j][u+1])res++;
        if(t[j][u]&&t[j+1][u])res++;
        }
    mini(allres,res);
    }
  printf("%d\n",allres);
  }
main()
{
int z;
scanf("%d",&z);
FOR(iii,1,z)
  {
  printf("Case #%d: ",iii);
  solve();
  }
}
