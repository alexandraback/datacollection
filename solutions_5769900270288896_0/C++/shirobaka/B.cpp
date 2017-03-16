#include <bits/stdc++.h>
using namespace std;
#define TR(i,v)       for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
#define DEBUG(x)      cout<<#x<<" = "<<x<<endl
#define SIZE(p)       (int)(p).size()
#define MP(a,b)       make_pair((a),(b))
#define ALL(p)        (p).begin(),(p).end()
#define rep(i,n)      for(int i=0;i<(int)(n);++i)
#define REP(i,a,n)    for(int i=(a);i<(int)(n); ++i)
#define FOR(i,a,b)    for(int i=(int)(a);i<=(int)(b);++i)
#define FORD(i,b,a)   for(int i=(int)(b);i>=(int)(a);--i)
#define CLR(x,y)      memset((x),(y),sizeof((x)))
typedef long long LL;
typedef pair<int,int> pii;
int n,m,K,g[20][20],dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int main(){
  int T;scanf("%d",&T);
  FOR(cs,1,T){
    printf("Case #%d: ",cs);
    scanf("%d%d%d",&n,&m,&K);
    int N=n*m;
    int res=(int)1e9;
    rep(msk,1<<N)if(__builtin_popcount(msk)==K){
      int c=0;
      rep(i,n)
      rep(j,m){
        if(msk>>c&1)
          g[i][j]=1;
        else
          g[i][j]=0;
        ++c;
        // printf("%d%c",g[i][j],j+1==m?'\n':' ');
      }
      int s=0;
      rep(i,n)
      rep(j,m){        
        rep(k,4){
          int ii=i+dx[k],jj=j+dy[k];
          if(ii>=0 && ii<n && jj>=0 && jj<m)
            s+=g[i][j] && g[ii][jj];
        }
      }
      assert(s%2==0);
      // DEBUG(s);
      s/=2;
      res=min(res,s);
    }
    printf("%d\n",res);
  }
  return 0;
}