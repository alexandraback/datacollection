#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<queue>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

#define N 1010
#define MP make_pair
int n,m,a[N];
LL check(LL t){
  LL cnt=0;
  FOR(i,n)
    cnt+=t/a[i]+1;
  return cnt;
}  
int getans(){
  int id=0;
  int c=0;
  priority_queue<pair<LL,int> ,vector<pair<LL,int> >,greater<pair<LL,int> > > pq;
  FOR(i,n)pq.push(MP(0ll,i));
  int t;
  while(c<m){
    pair<LL,int> p=pq.top();
    pq.pop();
    t=p.first;
    p.first+=a[p.second];
    pq.push(p);
    id=p.second;
    c++;
  }
  printf("t=%d\n",t);
  return id;
}
int main(){
#ifdef QWERTIER
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);
  //FILE* fans=fopen("sub-5.out","r");
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    printf("Case #%d: ",kase);
    scanf("%d%d",&n,&m);
    FOR(i,n)scanf("%d",&a[i]);
    LL lo=0,hi=100000000000000ll;
    while(lo<hi){
      LL mi=(lo+hi)>>1;
      if(check(mi)>=m)hi=mi;
      else lo=mi+1;
    }
    LL t=lo,c=0;
    int id=0;
    FOR(i,n){
      c+=t/a[i];
      if(t%a[i])
        c++;
    }
    FOR(i,n)if(t%a[i]==0){
      c++;
      if(c==m){
        printf("%d\n",i);
        break;
      }
    }
    if(0)if(getans()!=id){
      printf("%d\n",id);
    }
  }
  return 0;
}
