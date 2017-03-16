#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define mp make_pair
using namespace std;

const int N = 1005;
int a[N];


vector<pair<long long, int> > occ;
int main(){
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  int tt, i, n, k;
  scanf("%d",&tt);
  for(int cas=1;cas<=tt;++cas){

  printf("Case #%d: ", cas);
  scanf("%d%d",&n,&k);
  for(i=1;i<=n;++i)scanf("%d",&a[i]);
  long long l = 0, r = 100000000000000LL;
  while(l<=r){
    long long m = (l+r)>>1, tot=0;
    for(int i=1;i<=n;++i){
      tot+=m/a[i]+1;
    }
    if(tot<k) l=m+1;
    else r=m-1;
  }
  long long tot=0, tot1=0;
  for(int i=1;i<=n;++i){
    tot+=(l-1)/a[i]+1;
  }
  if(l==0 || l==1) tot=0;
  int res=k-tot, ans;
    for(int i=1;i<=n;++i){
      if(l%a[i]==0) tot++;
      if(tot==k){
        ans=i;
        break;
      }
    }
  
  printf("%d\n",ans);

  }
  return 0;
}
