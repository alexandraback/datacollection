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
int n,m,K,dx[]={-1,0,0,1},dy[]={0,-1,1,0},N;
struct DArray{
  int s[10005],n,m;
  int *operator[](int k){
    return s+k*m;
  }
}g;
inline bool isb(int i,int j){
  return ((i+j)&1)==0;
}
int gao1(){
  memset(g.s,0,sizeof(g.s));
  int K=::K;
  rep(i,n)
  rep(j,m)if(isb(i,j))g[i][j]=1,--K;
  vector<int> p;
  rep(i,n)
  rep(j,m)if(!isb(i,j)){
    int c=0;
    rep(k,4){
      int ii=i+dx[k],jj=j+dy[k];
      if(ii>=0 && ii<n && jj>=0 && jj<m)
        ++c;
    }
    p.push_back(c);
  }
  sort(ALL(p));
  int r=0;
  rep(i,K)r+=p[i];
  return r;
}
int gao2(){  
  int K=::K;
  rep(i,n)
  rep(j,m)if(!isb(i,j))--K;
  vector<int> p;
  rep(i,n)
  rep(j,m)if(isb(i,j)){
    int c=0;
    rep(k,4){
      int ii=i+dx[k],jj=j+dy[k];
      if(ii>=0 && ii<n && jj>=0 && jj<m)
        ++c;
    }
    p.push_back(c);
  }
  sort(ALL(p));
  int r=0;
  rep(i,K)r+=p[i];
  return r;
}
int main(){
  int T;scanf("%d",&T);
  FOR(cs,1,T){
    printf("Case #%d: ",cs);
    scanf("%d%d%d",&n,&m,&K);
    g.n=n,g.m=m;
    N=n*m;
    int res=(int)1e9;
    int bn=0,wn=0;
    rep(i,n)
    rep(j,m)bn+=isb(i,j);
    wn=N-bn;
    if(K<max(wn,bn)){
      puts("0");
      continue;
    }
    res=min(res,gao1());
    res=min(res,gao2());
    printf("%d\n",res);
  }
  return 0;
}