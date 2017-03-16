#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

#define N 1000
struct P{
  LL x,y;
  const inline bool operator<(const P &r)const{
    return x<r.x || (x==r.x&&y<r.y);
  }
  P operator-(const P& r){
    P ret;
    ret.x=x-r.x;
    ret.y=y-r.y;
    return ret;
  }
}p[N],tmp[N],ch[N];

int n;
LL Cross(P a,P b){
  return a.x*b.y-a.y*b.x;
}
bool check(int S,int cur){
  int m=0;
  REP(i,n)if((S>>i)&1)tmp[m++]=p[i];
  int sz=0;
  sort(tmp,tmp+m);
  REP(i,m){
    while(sz>1 && Cross(ch[sz-1]-ch[sz-2],tmp[i]-ch[sz-2])<0)sz--;
    ch[sz++]=tmp[i];
  }
  int k=sz;
  for(int i=m-2; i>=0; i--){
    while(sz>k && Cross(ch[sz-1]-ch[sz-2],tmp[i]-ch[sz-2])<0)sz--;
    ch[sz++]=tmp[i];
  }
  if(m>1)sz--;
  REP(i,sz)if(ch[i].x==p[cur].x && ch[i].y==p[cur].y)return true;
  return false;
}
int count(int S){
  int ret=0;
  REP(i,n)ret+=((S>>i)&1);
  return ret;
}
int ans[N];
int main(){
#ifdef QWERTIER
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    printf("Case #%d:\n",kase);
    scanf("%d",&n);
    REP(i,n){
      scanf("%I64d%I64d",&p[i].x,&p[i].y);
    }
    memset(ans,0x3f,sizeof(ans));
    REP(i,n){
      REP(S,(1<<n)){
        if(((S>>i)&1)^1)continue;
        if(n-count(S)>=ans[i])continue;
        if(check(S,i))ans[i]=min(ans[i],n-count(S));
      }
      printf("%d\n",ans[i]);
    }
  }
  return 0;
}
