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
map<int,map<int,int> > t;
void solve()
  {
  scanf("%d%d%d",&n,&m,&x);
  
  
  int allres=1e9;
  int xx=0;
  bool ok1=1,ok2=1;
  REP(xx,2)
    {
    t.clear();
    int dodad=0;
    int juz=x;
    FOR(i,1,n)
       {
       FOR(j,1,m)
         {
         if(abs((i-j)%2)==xx)
          {
          t[i][j]=1;
          juz--;
          }
         }
       }
    if(juz<=0)
      {
      allres=0;
      break;
      }
    if(t[1][1]==0&&juz)
      {
      t[1][1]=1;
      juz--;
      }
    if(t[n][1]==0&&juz)
      {
      t[n][1]=1;
      juz--;
      }
    if(t[1][m]==0&&juz)
      {
      t[1][m]=1;
      juz--;
      }
    if(t[n][m]==0&&juz)
      {
      t[n][m]=1;
      juz--;
      }
    FOR(i,1,n)
      {
      if(t[i][1]==0&&juz)
        {
        t[i][1]=1;
        juz--;
        }
      if(t[i][m]==0&&juz)
        {
        t[i][m]=1;
        juz--;
        }
      }
    FOR(i,1,m)
      {
      if(t[n][i]==0&&juz)
        {
        t[n][i]=1;
        juz--;
        }
      if(t[1][i]==0&&juz)
        {
        t[1][i]=1;
        juz--;
        }
      }
    
    FOR(i,1,n)
       {
       FOR(j,1,m)
        if(juz&&t[i][j]==0)
          {
          t[i][j]=1;
          juz--;
          }
       }
       
    int res=0;
    FOR(i,1,n)
      FOR(j,1,m)
        {
        if(t[i][j]&&t[i][j+1])res++;
        if(t[i][j]&&t[i+1][j])res++;
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
